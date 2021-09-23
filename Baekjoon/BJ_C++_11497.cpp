// The problem link : https://www.acmicpc.net/problem/11497
// The result : 2160KB, 40ms
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n);
        vector<int> temp(n);
        for(int i=0; i<n; i++) cin >> v[i];
        sort(v.begin(),v.end());
        int left = 0, right = n-1, pos = 0, ans = 0;
        while(left<=right&&pos<n){
            if(pos<n) temp[left] = v[pos];
            pos++;
            if(pos<n) temp[right] = v[pos];
            pos++;
            left++;
            right--;
        }
        for(int i=0; i<n-1; i++) ans = max(ans,abs(temp[i+1]-temp[i]));
        ans = max(ans,abs(temp[0]-temp[n-1]));
        cout << ans << "\n";
    }
    return 0;
}
