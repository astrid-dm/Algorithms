#include <iostream>
#include <algorithm>
#include <vector>
#define STD 500

using namespace std;

int arr[9],n,k,ans=0;
bool ch[9];

void workout(int cnt, int total) {
    if (total < STD) return;
    if (cnt == n) {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!ch[i]) {
            ch[i] = true;
            workout(cnt + 1, total - k + arr[i]);
            ch[i] = false;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        ch[i] = true;
        workout(1, 500-k+arr[i]);
        ch[i] = false;
    }
    cout << ans << "\n";
    return 0;
}
