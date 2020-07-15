#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9 + 3;
const int N = 1e5 + 1;
const int MOD = 998244353;
const double EPS = 1e-9;
 
const double PI = acos(-1);
 
 
vector<int> gr[N];
vector<char> color(N);
vector<int> p(N, -1);
int c_start, c_end;
 
bool dfs(int vert) {
    color[vert] = 1;
    for (int i = 0; i < gr[vert].size(); i++) {
        int to = gr[vert][i];
        if (color[to] == 0) {
            p[to] = vert;
            if (dfs(to))
                return true;
        } else if (color[to] == 1) {
            c_end = vert;
            c_start = to;
            return true;
        }
    }
    color[vert] = 2;
    return false;
}
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
    }
    c_start = -1;
    for (int x = 1; x <= n; x++)
        if (dfs(x))
            break;
    if (c_start == -1) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        vector<int> cycle;
        cycle.push_back(c_start);
        for (int v = c_end; v != c_start; v = p[v])
            cycle.push_back(v);
        cycle.push_back(c_start);
        reverse(cycle.begin(), cycle.end());
        cycle.pop_back();
        for (int i = 0; i < cycle.size(); ++i)
            cout << cycle[i] << ' ';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
