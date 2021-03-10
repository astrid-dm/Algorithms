#include <iostream>
#include <algorithm>
#include <vector>
const int MAX = 16;
using namespace std;

int l=0,c=0;
vector<char> v;
bool ch[MAX] = {false,};

void go(int start, string s){
    if(s.size()==l){
        bool vo = false; // 모음
        int con = 0; // 자음 갯수
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') vo = true;
            else con++;
        }
        if(vo&&con>=2) cout << s << "\n";
        return;
    }
    for(int i=start; i<v.size(); i++){
        if(!ch[i]){
            ch[i] = true;
            go(i+1, s+v[i]);
            ch[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> l >> c;
    for(int i=0; i<c; i++){
        char temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    go(0,"");
    return 0;
}
