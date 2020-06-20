#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 3;
const int N = 1e4;
const int MOD = 998244353;
const double EPS = 1e-9;

const double PI = acos(-1);


int dijkstra(vector<vector<int>> &gr, int s, int f) {
    int n = gr->size() - 1;
    vector<char> used(n + 1);
    vector<int> dist(n + 1, INF);
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        int v = 0;
        for (int j = 1; j <= n; j++)
            if (!used[j] && (!v || dist[j] < dist[v]))
                v = j;
        if (dist[v] == INF)
            break;
        used[v] = 1;
        for (int j = 1; j <= n; j++) {
            int lng = gr->at(v)[j];
            if (lng < 0)
                continue;
            dist[j] = min(dist[j], dist[v] + lng);
        }
    }
    if (dist[f] == INF)
        dist[f] = -1;
    return dist[f];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, s, f;
    cin >> n >> s >> f;
    vector<vector<int>> gr(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> gr[i][j];
    cout << dijkstra(gr, s, f);
}
