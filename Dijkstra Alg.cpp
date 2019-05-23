#include <bits/stdc++.h>


using namespace std;

#define BIG 1000000

int main() {

    int start, end, n;
    cin >> n;

    vector< vector< pair<int, int> > > g(n);

    for(int i = 0; i < n; i++) {
        int num, vertex, length;
        vector< pair<int, int> > tmp;
        cin >> num;
        for(int j = 0; j < num; j++) {
            cin >> vertex >> length
            tmp.push_back(make_pair(vertex, length));
        }
        g[i] = tmp;
    }

    vector<int> d(n), label(n);
    bool used[n] = {};

    d.assign(n, BIG);

    start = 0;
    end = 3;

    d[start] = 0;

    int vert;
    bool first = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!used[j] && (first || d[j] < d[vert])) {
                first = 0;
                vert = j;
            }
        }
        used[vert] = 1;
        for(int j = 0; j < g[vert].size(); j++) {
            int to = g[vert][j].first, way = g[vert][j].second;
            if(d[vert] + way < d[to]) {
                d[to] = d[vert] + way;
                label[to] = vert;
            }
        }
        first = 1;
    }

    cout << "Path from start to end:\n";
    vector<int> path;
    for(int v = end; v != start; v = label[v]) {
        path.push_back(v);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " -> ";
    cout << "== " << d[end];
}
