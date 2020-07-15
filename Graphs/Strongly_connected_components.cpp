#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 2e9 + 3;
const int N = 3e3 + 1;
const int MOD = 998244353;
const double EPS = 1e-9;
 
const double PI = acos(-1);
 
 
vector<int> gr[N], gt[N];
vector<char> used(N, 0);
vector<int> order, comp;
map<int, vector<int>> g;
 
 
void dfs1(int s) {
    used[s] = 1;
    for (int v : gr[s])
        if (!used[v])
            dfs1(v);
    order.push_back(s);
}
 
void dfs2(int s) {
    used[s] = 1;
    comp.push_back(s);
    for (int v : gt[s])
        if (!used[v])
            dfs2(v);
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        gr[from].push_back(to);
        gt[to].push_back(from);
    }
    for (int v = 1; v <= n; v++) {
        if (!used[v])
            dfs1(v);
    }
    used.assign(N, 0);
    for (int v = 1; v <= n; v++) {
        int cur = order[n - v];
        if (!used[cur]) {
            dfs2(cur);
            set<int> from, to;
            for (int x : comp)
                from.insert(x);
            for (int x : comp) {
                for (int y : gr[x])
                    if (!from.count(y))
                        to.insert(y);
            }
            for (int x : to)
                g[comp.back()].push_back(x);
            if (to.empty())
                g[comp.back()] = vector<int>();
            comp.clear();
        }
    }
    vector<int> res;
    for (auto x : g) {
        if (x.second.empty())
            res.push_back(x.first);
    }
    cout << res.size() << endl;
    for (int x : res)
        cout << x << ' ';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("firesafe.in", "r", stdin);
    freopen("firesafe.out", "w", stdout);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
