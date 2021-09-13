// The problem link : https://www.acmicpc.net/problem/2283
// The result : 5928KB, 452ms
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
 
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k,st,ed,left=0,right=0, maxi = 0;
    unsigned long long sum = 0;
    vector<int> v(MAX,0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> st >> ed;
        for(int j=st+1; j<=ed; j++) v[j]++; // 주의
        maxi = max(ed,maxi);
    }
    while(right<=maxi){
        if(sum>k){
            left++;
            sum -= v[left];
        }else if(sum==k){
            cout << left << " " << right << "\n";
            exit(0);
        }else{ // sum < k
            right++;
            sum += v[right];
        }
    }
    cout << 0 << " " << 0 << "\n";
    return 0;
}
