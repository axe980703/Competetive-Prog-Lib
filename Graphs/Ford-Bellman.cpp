#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18 + 3;
const int N = 1e4;
const int MOD = 998244353;
const double EPS = 1e-9;

const double PI = acos(-1);

class edge {
public:
    int from;
    int to;
    long long w;

    edge(int from, int to, long long w) : from(from), to(to), w(w) {};
};

void ford_bellman(vector<edge> &gr, int n, int s) {
    vector<long long> d(n + 1, INF);
    d[s] = 0;
    set<int> neg;
    for (int i = 0; i < n; i++) {
        for (edge e : gr) {
            if (d[e.from] < INF && d[e.from] + e.w < d[e.to]) {
                if (i == n - 1)
                    neg.insert(e.to);
                else
                    d[e.to] = d[e.from] + e.w;
            }
        }
    }
    vector<int> g[n + 1];
    for (edge e : gr)
        g[e.from].push_back(e.to);
    vector<char> used(n + 1, 0);

    function<void(int)> dfs = [&](int vert) {
        used[vert] = 1;
        for (int x : g[vert])
            if (!used[x])
                dfs(x);
    };

    for (int x : neg) {
        if (!used[x])
            dfs(x);
    }
    for (int x = 1; x <= n; x++) {
        if (d[x] == INF)
            cout << '*';
        else if (used[x])
            cout << '-';
        else
            cout << d[x];
        cout << endl;
    }
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<edge> gr;
    for (int i = 0; i < m; i++) {
        int b, e;
        long long w;
        cin >> b >> e >> w;
        gr.push_back(edge(b, e, w));
    }
    ford_bellman(gr, n, s);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
