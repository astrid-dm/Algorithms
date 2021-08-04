// The problem link : https://www.acmicpc.net/problem/1522
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    int a=0, ans=s.size();
    for(auto c : s) if(c=='a') a++;
    for(int i=0; i<s.size(); i++){
        int cnt = a, temp = 0;
        for(int j=i; j<i+s.size(); j++){
            if(cnt==0) break;
            if(s[j%s.size()]=='b') temp++, cnt--;
            else cnt--;
        }
        ans = min(ans,temp);
    }
    cout << ans << "\n";
    return 0;
}
