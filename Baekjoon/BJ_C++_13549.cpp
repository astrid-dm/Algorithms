// The problem link : https://www.acmicpc.net/problem/13549
#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int n,m,pos,cnt;
bool ch[MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    ch[n] = true;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,n});
    while(!q.empty()){
        cnt = q.top().first;
        pos = q.top().second;
        q.pop();
        if(pos==m){
            cout << cnt << "\n";
            exit(0);
        }
        if(pos*2<MAX&&!ch[pos*2]){
            ch[pos*2] = true;
            q.push({cnt,pos*2});
        }
        if(pos-1>=0&&!ch[pos-1]){
            ch[pos-1] = true;
            q.push({cnt+1,pos-1});
        }
        if(pos+1<MAX&&!ch[pos+1]){
            ch[pos+1] = true;
            q.push({cnt+1,pos+1});
        }
    }
    return 0;
}
