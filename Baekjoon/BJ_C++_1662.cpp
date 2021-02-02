#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

string s = "";
bool ch[51] = {false,};

int dfs(string &s, int idx){
    int cnt = 0;
    for(int i=idx; i<s.size(); i++){
        if(s[i]=='('&&!ch[i]){
            ch[i] = true;
            int num = s[i-1]-'0';
            cnt--;
            cnt += num*dfs(s,i+1);
        }
        else if(s[i]==')'&&!ch[i]){
            ch[i] = true;
            return cnt;
        }
        else if(!ch[i]){
            ch[i] = true;
            cnt++;
        }
    }
    return cnt;
}

int main(void) {
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    cout << dfs(s,0);
   return 0;
}
