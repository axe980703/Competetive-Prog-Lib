#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e18 + 7;

struct edge {
    int u, v, w;
};

void ford_bellman(vector<edge> &edgs, int n, int s) {
    vector<long long> d(n + 1, INF);
    d[s] = 0;
    vector<int> neg;
    for (int i = 0; i < n; i++) {
        for (auto[u, v, w]: edgs) {
            if (d[u] == INF) continue;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (i == n - 1)
                    neg.push_back(u);
            }
        }
    }
    // now processing cases of negative cycles
    vector<int> gr[n + 1];
    for (auto[u, v, w]: edgs)
        gr[u].push_back(v);
    vector<char> used(n + 1);
    function<void(int)> dfs = [&](int cur) {
        used[cur] = 1;
        d[cur] = -1;
        for (int v : gr[cur])
            if (!used[v])
                dfs(v);
    };
    for (int v : neg) {
        if (!used[v])
            dfs(v);
    }
    // d[v] now contains value of shortest path from s, if v is reachable from negative cycle then d[v] = -1,
    // if v isn't reachable at all then d[v] = INF
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<edge> gr;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        gr.push_back({u, v, w});
    }
    ford_bellman(gr, n, s);
}

