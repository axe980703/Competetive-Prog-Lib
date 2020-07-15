#include <bits/stdc++.h>
 
using namespace std;
 
const int INF = 1e9 + 3;
const int N = 1e5 + 1;
const int MOD = 998244353;
const double EPS = 1e-9;
 
const double PI = acos(-1);
 
 
void floyd_warshall(vector<vector<int>> &d, int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
 
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    floyd_warshall(d, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("floyd.in", "r", stdin);
    freopen("floyd.out", "w", stdout);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
