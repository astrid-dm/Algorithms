// 19600KB, 240ms
#include <iostream>
#include <algorithm>
#define MAX 1500002

using namespace std;

int arr[MAX][2], dp[MAX], ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, t, p, pos;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t >> p;
        arr[i][0] = t;
        arr[i][1] = p;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = max(ans, dp[i]);
        if (i + arr[i][0] <= n + 1) {
            dp[i+arr[i][0]] = max(dp[i + arr[i][0]], dp[i] + arr[i][1]);
        }
        ans = max(ans, dp[i]);
    }
    ans = max(ans, dp[n + 1]);
    cout << ans << "\n";
    return 0;
}
