// The problem link : https://www.acmicpc.net/problem/12919
#include <iostream>
#include <algorithm>
using namespace std;

string temp = "";

void abGame(string a, string b){
    if(a==b){
        cout << 1 << "\n";
        exit(0);
    }
    if(a.size()>=b.size()) return;
    if(b[b.size()-1]=='A'){
        temp = b;
        temp.erase(temp.size()-1);
        abGame(a,temp);
    }
    if(b[0]=='B'){
        temp = b;
        temp.erase(temp.begin());
        reverse(temp.begin(),temp.end());
        abGame(a,temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s,t;
    cin >> s >> t;
    abGame(s,t);
    cout << 0 << "\n";
    return 0;
}
