#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int a[n][m], dp[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (i == 0 || j == 0) dp[i][j] = a[i][j];
                else {
                    if (a[i][j]) dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    else dp[i][j] = 0;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, dp[i][j]);
            }
        }
        cout << res << endl;
    }
}