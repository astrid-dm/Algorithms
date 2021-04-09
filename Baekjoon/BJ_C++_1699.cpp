#include <iostream>
#define MAX 100001
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, arr[MAX];
    cin >> n;
    for(int i=1; i<=n; i++){
        arr[i] = i;
        for(int j=1; j*j<=i; j++){
            if(arr[i]>arr[i-j*j]+1) arr[i] = arr[i-j*j]+1;
        }
    }
    cout << arr[n] << "\n";
    return 0;
}
