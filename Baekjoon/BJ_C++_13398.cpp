#include <iostream>
#define MAX 100001
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, ans = -1e9, arr[MAX], dp1[MAX], dp2[MAX];
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        dp1[i] = arr[i];
        dp2[i] = arr[i];
    }
    for(int i=2; i<=n; i++) dp1[i] = max(arr[i],arr[i]+dp1[i-1]); // i에서 끝나는 수열
    for(int i=n-1; i>=1; i--) dp2[i] = max(arr[i],arr[i]+dp2[i+1]); // i에서 시작하는 수열
    for(int i=1; i<=n; i++){
        ans = max(ans,dp1[i]);
        if(i>=2&&i<=n-1)ans = max(ans,dp1[i-1]+dp2[i+1]);
    }
    cout << ans << "\n";
    return 0;
}
