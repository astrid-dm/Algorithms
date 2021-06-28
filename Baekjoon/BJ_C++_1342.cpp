// The problem link : https://www.acmicpc.net/problem/1342
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int ans = 0;
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    do{
        bool ch = true;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]==s[i+1]) ch = false;
            if(!ch) break;
        }
        if(ch) ans++;
    }while(next_permutation(s.begin(),s.end()));
    cout << ans << "\n";
    return 0;
}
