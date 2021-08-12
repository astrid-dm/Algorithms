// The problem link : https://www.acmicpc.net/problem/22233
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,total = 0;
    string s="",temp="",k="";
    unordered_set<string> st;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> s;
        st.insert(s);
    }
    while(m--){
        cin >> temp;
        int pos = 0;
        while(pos<temp.length()){
            auto it = temp.find(',',pos);
            if(it==temp.npos){
                k = temp.substr(pos);
                if(st.find(k)!=st.end()) st.erase(k);
                break;
            }
            else{
                k = temp.substr(pos, it-pos);
                if(st.find(k)!=st.end()) st.erase(k);
                pos = it+1;
            }
        }
        cout << st.size() << "\n";
    }
    return 0;
}
