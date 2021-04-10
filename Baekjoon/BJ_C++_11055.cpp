#include <iostream>
#define MAX 1001
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, len = 1, ans = 0, arr[MAX] = {0,}, dp[MAX] = {0,};
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }
    ans = dp[1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(arr[i]>arr[j]&&dp[i]<dp[j]+arr[i]){
                dp[i] = dp[j] + arr[i];
                if(dp[i]>ans) ans = dp[i];
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
