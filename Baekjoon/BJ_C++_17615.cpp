// The problem link : https://www.acmicpc.net/problem/17615
#include <iostream>
#include <algorithm>
using namespace std;

int n,cnt,ans=987654321;
string s;

void group(char x){
    cnt = 0;
    bool ch = false;
    for(int i=0; i<s.size(); i++){ // left
        if(s[i]!=x) ch = true;
        else if(ch&&s[i]==x) cnt++;
    }
    if(ans>cnt) ans = cnt;
    ch = false;
    cnt = 0;
    for(int i=s.size()-1; i>=0; i--){ // right
        if(s[i]!=x) ch = true;
        else if(ch&&s[i]==x) cnt++;
    }
    if(ans>cnt) ans = cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> s;
    group('R');
    group('B');
    cout << ans << "\n";
    return 0;
}
