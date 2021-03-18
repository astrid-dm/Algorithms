#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 10000
using namespace std;

int arr[MAX], ans = -1e4;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, cnt = 0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n);
    do{
        int temp = 0;
        for(int i=1; i<n; i++) temp += abs(arr[i]-arr[i-1]);
        if(ans<temp) ans = temp;
    }while(next_permutation(arr,arr+n));
    cout << ans << "\n";
    return 0;
}
