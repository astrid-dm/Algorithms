#include <iostream>
#define MAX 1001
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, ans = 1, arr[MAX], pl[MAX], mi[MAX];
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        pl[i] = 1;
        mi[i] = 1;
    }
    for(int i=2; i<=n; i++){ // 증가
        for(int j=1; j<i; j++){
            if(arr[i]>arr[j]&&pl[i]<pl[j]+1) pl[i] = pl[j]+1;
        }
    }
    for(int i=n; i>0; i--){
        for(int j=i+1; j<=n; j++){
            if(arr[i]>arr[j]&&mi[i]<mi[j]+1) mi[i] = mi[j]+1;
        }
    }
    for(int i=1; i<=n; i++){
        if(ans<pl[i]+mi[i]-1) ans = pl[i] + mi[i]-1;
    }
    cout << ans << "\n";
    return 0;
}
