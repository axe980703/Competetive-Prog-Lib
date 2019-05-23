#include <bits/stdc++.h>


using namespace std;

#define BIG 1000000

int main() {

    int start, end, n;
    cin >> n;

    vector<vector<pair<int, int>>> g(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            cin >> g[i][j].first >> g[i][j].second;
        }
    }

    vector<int> d(n), label(n);
    bool used[n] = {};

    d.assign(n, BIG);

    start = 3;

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
        if(vert == end)
            break;
        for(int j = 0; j < g[vert].size(); j++) {
            int to = g[vert][j].first, way = g[vert][j].second;
            if(d[vert] + way < d[to]) {
                d[to] = d[vert] + way;
                label[to] = vert;
            }
        }
    }

    cout << "Path from start to end:\n";
    vector<int> path;
    int way = 0;
    for(int v = end; v != start; v = label[v]) {
        way += d[v];
        path.push_back(v);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " -> ";
    cout << "== " << way;
}






