// The problem link : https://www.acmicpc.net/problem/14395
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct four{
    unsigned long long num;
    string ans;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int mini = 0, div = 0;
    unsigned long long s,t;
    cin >> s >> t;
    queue<four> q;
    q.push({s,""});
    while(!q.empty()){
        unsigned long long a = q.front().num;
        string temp = q.front().ans;
        q.pop();
        if(a==t){
            if(temp=="") cout << 0 << "\n";
            else cout << temp << "\n";
            exit(0);
        }
        if(a*a<=t&&a*a>1) q.push({a*a,temp+'*'}); // '*'
        if(a+a<=t&&a+a>0) q.push({a+a,temp+'+'}); // '+'
        if(mini==0){
            q.push({0,temp+'-'}); // '-'
            mini=1;
        }
        if(div==0){
            q.push({1,temp+'/'}); // '/'
            div = 1;
        }
    }
    cout << -1 << "\n";
    return 0;
}
