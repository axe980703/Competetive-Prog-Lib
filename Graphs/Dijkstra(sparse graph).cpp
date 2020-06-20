#include <bits/stdc++.h>
 
using namespace std;
 
const long long INF = 1e18 + 3;
const int N = 1e4;
const int MOD = 998244353;
const double EPS = 1e-9;
 
const double PI = acos(-1);
 
class edge {
public:
    int to;
    int w;
 
    edge(int to, int w) {
        this->to = to;
        this->w = w;
    }
};
 
void dijkstra_sparse(vector<vector<edge>> &gr, int n, int s, int f) {
    vector<long long> d(n + 1, INF);
    vector<int> p(n + 1);
    d[s] = 0;
    set<pair<long long, int>> mn;
    mn.insert(make_pair(d[s], s));
    while (!mn.empty()) {
        int cur = mn.begin()->second;
        mn.erase(mn.begin());
        for (auto x : gr[cur]) {
            int to = x.to;
            auto lng = x.w;
            if (d[cur] + lng < d[to]) {
                mn.erase(make_pair(d[to], to));
                d[to] = d[cur] + lng;
                p[to] = cur;
                mn.insert(make_pair(d[to], to));
            }
        }
    }
    if (d[f] == INF) {
        cout << -1;
        return;
    }
    cout << d[f] << endl;
    vector<int> path;
    for (int vert = f; vert != s; vert = p[vert])
        path.push_back(vert);
    path.push_back(s);
    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << ' ';
}
 
void solve() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    vector<vector<edge>> gr(n + 1);
    for (int i = 0; i < m; i++) {
        int b, e, w;
        cin >> b >> e >> w;
        gr[b].push_back(edge(e, w));
        gr[e].push_back(edge(b, w));
    }
    dijkstra_sparse(gr, n, s, f);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
