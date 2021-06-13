// The problem link : https://www.acmicpc.net/problem/2212
#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k,temp,ans=0;
    cin >> n;
    vector<int> v(n);
    vector<int> gap;
    cin >> k;
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    ans = v[v.size()-1]-v[0];
    for(int j=1; j<n; j++){
        temp = v[j]-v[j-1];
        gap.push_back(temp);
    }
    sort(gap.begin(),gap.end(),greater<int>());
    for(int i=0; i<k-1; i++){
        if(i+1>=n) break;
        ans-=gap[i];
    }
    cout << ans << "\n";
    return 0;
}
