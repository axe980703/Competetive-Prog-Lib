#include <bits/stdc++.h>
 
using namespace std;
 
const long long INF = 2e18 + 7;
 
struct edge {
    int v, w;
};
 
void dijkstra_sparse(vector<vector<edge>> &gr, int n, int s) {
    vector<long long> d(n + 1, INF);
    vector<int> p(n + 1);
    d[s] = 0;
    set<pair<long long, int>> st;
    st.insert({0, s});
    while (!st.empty()) {
        int cur = st.begin()->second;
        st.erase(st.begin());
        for (auto[v, w]: gr[cur]) {
            if (d[cur] + w < d[v]) {
                st.erase({d[v], v});
                d[v] = d[cur] + w;
                p[v] = cur;
                st.insert({d[v], v});
            }
        }
    }
    // d[v] now contains value of shortest path from s to v, if path doesn't exists then d[v] = INF
    // p[v] contains direct parent of vertex v on shortest path from s, if v isn't reacheble then p[v] = 0
}
 
int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<edge>> gr(n + 1);
    for (int i = 0; i < m; i++) {
        int b, e, w;
        cin >> b >> e >> w;
        gr[b].push_back(edge(e, w));
        gr[e].push_back(edge(b, w));
    }
    dijkstra_sparse(gr, n, s);
}
