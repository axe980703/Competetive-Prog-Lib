#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 3;
const int N = 1e3 + 5;
const int MOD = 998244353;
const double EPS = 1e-9;

const double PI = acos(-1);


vector<int> find_euler_path(int start, vector<vector<int>> gr) {
    int n = gr.size() - 1;
    vector<int> res;
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int cur = st.top();
        int deg = 0, to = -1;
        for (int v = 1; v <= n; v++) {
            deg += gr[cur][v];
            if (gr[cur][v])
                to = v;
        }
        if (deg) {
            gr[cur][to]--;
            gr[to][cur]--;
            st.push(to);
        } else {
            res.push_back(cur);
            st.pop();
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> gr(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            gr[i][a]++;
        }
    }
    int start = 1;
    for (int from = 1; from <= n; from++) {
        int cnt = 0;
        for (int to = 1; to <= n; to++)
            cnt += gr[from][to];
        if (cnt & 1) {
            start = from;
            break;
        }
    }
    auto res = find_euler_path(start, gr);
    cout << res.size() - 1 << endl;
    for (int x : res)
        cout << x << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("post.in", "r", stdin);
    freopen("post.out", "w", stdout);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
