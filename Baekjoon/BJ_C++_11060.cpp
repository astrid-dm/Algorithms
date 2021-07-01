// The problem link : https://www.acmicpc.net/problem/11060
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, temp;
    cin >> n;
    vector<int> v(n);
    vector<int> ans(n,0);
    if (n == 1) {
        cout << 0 << "\n";
        exit(0);
    }
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= i + v[i]; j++) {
            if (j >= n) break;
            if (ans[j] != 0) continue;
            if (i != 0 && ans[i] == 0) break;
            ans[j] = ans[i] + 1;
            if (j == n - 1 && ans[j] != 0) {
                cout << ans[j] << "\n";
                exit(0);
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
