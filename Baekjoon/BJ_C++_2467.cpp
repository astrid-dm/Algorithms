// The problem link : https://www.acmicpc.net/problem/2467
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int left=0,right=0,n=0, sum = 2000000000, temp = 0;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int le=0, ri=n-1;
    while(le<ri){
        temp = v[le]+v[ri];
        if(abs(sum)>abs(temp)){
            left = v[le];
            right = v[ri];
            sum = temp;
        }
        if(temp>0) ri--;
        else le++;
    }
    cout << left << " " << right << "\n";
    return 0;
}
