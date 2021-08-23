// The problem link : https://www.acmicpc.net/problem/2512
// Result : 2180KB, 0ms
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n=0,m=0,le=0,ri=0,sum=0,mid=0,ans=0;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    cin >> m;
    sort(v.begin(),v.end());
    ri = v[n-1]*n;
    while(le<=ri){
        sum = 0;
        mid = (le+ri)/2;
        for(int i=0; i<n; i++){
            if(v[i]<=mid) sum+=v[i];
            else sum+=mid; 
        }
        if(sum<=m){
            ans = mid;
            le = mid+1;
        }else ri = mid-1;
    }
    if(v[n-1]>mid) cout << ans << "\n";
    else cout << v[n-1] << "\n";
    return 0;
}
