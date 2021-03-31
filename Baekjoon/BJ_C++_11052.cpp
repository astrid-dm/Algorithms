#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, arr[1001];
    cin >> n;
    arr[0] = 0;
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            arr[i] = max(arr[i],arr[j]+arr[i-j]);
        }
    }
    cout << arr[n] << "\n";
    return 0;
}
