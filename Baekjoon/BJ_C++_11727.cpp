#include <iostream>
using namespace std;

int n = 0, arr[1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 3;
    for(int i=3; i<=n; i++) arr[i] = (arr[i-2]+arr[i-1]+arr[i-2])%10007;
    cout << arr[n] << "\n";
    return 0;
}
