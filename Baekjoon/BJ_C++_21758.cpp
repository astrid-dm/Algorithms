// The problem link : https://www.acmicpc.net/problem/21758
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0;
    cin >> n;
    unsigned long long ans = 0, temp = 0;
    vector<int> v(n+1,0);
    for(int i=1; i<=n; i++) cin >> v[i];
    // 1. 벌벌 꿀
    for(int i=3; i<=n; i++) temp += v[i];
    if(temp>ans) {ans=temp; temp = 0;}
    for(int i=n-2; i>=1; i--) temp += v[i];
    if(temp>ans) {ans=temp; temp=0;}
    // 2. 벌 벌 꿀 
    int i=1;
    for(int j=i+1; j<=n-1; j++){
        temp = 0;
        for(int x=j+1; x<=n; x++) temp += v[x];
        for(int x=i+1; x<=n; x++){
            if(x==j) continue;
            temp += v[x];
        }
        if(temp>ans) ans = temp;
    }
    i=n;
    for(int j=i-1; j>=2; j--){
        temp = 0;
        for(int x=j-1; x>=1; x--) temp += v[x];
            for(int x=i-1; x>=1; x--){
                if(x==j) continue;
                temp += v[x];
        }
        if(temp>ans) ans = temp;
    }
    // 3. 벌 꿀 벌
    int pos = 2; 
    while(pos<n){
        temp = 0;
        for(int i=2; i<=pos; i++) temp += v[i];
        for(int j=n-1; j>=pos; j--) temp += v[j];
        if(temp>ans) ans = temp;
        pos++;
    }
    cout << ans << "\n";
    return 0;
}
