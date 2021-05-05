#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, sum = 0, cnt = 1, ans = MAX;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int left = 0, right = 0;
    sum = v[left];
    while(left<=right&&right<n){
        if(sum<m){
            right++;
            cnt++;
            sum+=v[right];
        }
        else{
            if(cnt<ans) ans = cnt;
            sum-=v[left];
            left++;
            cnt--;
            if(left>right&&left<n){
                right=left;
                cnt=1;
                sum+=v[right];
            }
        }
    }
    if(ans==MAX) ans = 0;
    cout << ans << "\n";
    return 0;
}
