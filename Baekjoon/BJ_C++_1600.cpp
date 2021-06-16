// The problem link : https://www.acmicpc.net/problem/1600
#include <iostream>
#include <algorithm>
#include <vector> 
#include <queue>
using namespace std;

struct monkey{
    int move,horse;
    int yy, xx;
};

int m,hs,y,x,nm,ny,nx,my[]={-1,-2,-2,-1,1,2,2,1,1,0,-1,0},mx[]={-2,-1,1,2,2,1,-1,-2,0,-1,0,1}; // 앞 8개는 체스 말, 뒤 4개는 인접한 사방위

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k,h,w;
    cin >> k;
    cin >> w >> h;
    vector<vector<int>> v(h+1,vector<int>(w+1,0));
    vector<vector<vector<bool>>> ch(h+1,vector<vector<bool>>(w+1,vector<bool>(k+1,false)));
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++) cin >> v[i][j];
    }
    queue<monkey> q;
    q.push({0,0,1,1});
    ch[1][1][0] = true;
    while(!q.empty()){
        m = q.front().move;
        hs = q.front().horse;
        y = q.front().yy;
        x = q.front().xx;
        q.pop();
        if(y==h&&x==w){
            cout << m << "\n";
            exit(0);
        }
        for(int i=0; i<12; i++){
            if(hs==k&&i<8) continue;
            ny = y+my[i];
            nx = x+mx[i];
            if(ny<=0||ny>h||nx<=0||nx>w) continue;
            if(v[ny][nx]==1) continue;
            if(i<8){
                if(hs+1>k) continue;
                if(ch[ny][nx][hs+1]) continue;
                ch[ny][nx][hs+1] = true;
                q.push({m+1,hs+1,ny,nx});
            }
            else{
                if(ch[ny][nx][hs]) continue;
                ch[ny][nx][hs] = true;
                q.push({m+1,hs,ny,nx});
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
