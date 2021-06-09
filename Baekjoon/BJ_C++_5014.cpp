// The problem link : https://www.acmicpc.net/problem/5014
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;
    vector<bool> ch(f+1,false);
    queue<pair<int,int>> q;
    q.push({s,0});
    ch[s] = true;
    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(now==g){
            cout << cnt << "\n";
            exit(0);
        }
        if(now+u<=f&&now+u>now&&!ch[now+u]) { ch[now+u] = true; q.push({now+u,cnt+1}); }
        if(now-d>=1&&now-d<now&&!ch[now-d]) { ch[now-d] = true; q.push({now-d,cnt+1}); }
    }    
    cout << "use the stairs" << "\n";
    return 0;
}
