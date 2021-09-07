// The problem link : https://www.acmicpc.net/problem/9024
// The result : 6048KB, 400ms
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 987654321
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];
        sort(v.begin(),v.end());
        int left=0, right=n-1, goal = MAX, cnt = 0, temp = 0, sum = 0;
        while(left<right){
            sum = v[left] + v[right];
            temp = abs(k-sum);
            if(temp<goal){
                goal = temp;
                cnt = 1;
            }else if(temp==goal) cnt++;
            if(sum>k) right--;
            else left++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
