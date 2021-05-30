// The problem link : https://www.acmicpc.net/problem/16973
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int ans = 0, g,n,m,y,yy,xx,x,ny,nyy,nxx,nx,my[]={1,-1,0,0},mx[]={0,0,1,-1}, h,w,s1,s2,f1,f2; // s1 -> f1, s2 -> f2;
bool ch[1001][1001];
vector<vector<int>> v;

struct box{
    int y1, x1, y2, x2, cnt;
};

bool canwego(int y1, int x1, int y2, int x2, int d){
    if(d==0){ // 1,0
        if(x1+w-1<0||x1+w-1>m) return true;
        for(int a=x1; a<x1+w; a++){
            if(v[y2][a]==1) return true;
        }
    }
    else if(d==1){ // -1,0
        if(x1+w-1<0||x1+w-1>m) return true;
        for(int a=x1; a<x1+w; a++){
            if(v[y1][a]==1) return true;
        }
    }
    else if(d==2){ // 0,1
        if(y1+h-1<0||y1+h-1>n) return true;
        for(int a=y1; a<y1+h; a++){
            if(v[a][x2]==1) return true;
        }
    }
    else if(d==3){ // 0,-1
        if(y1+h-1<0||y1+h-1>n) return true;
        for(int a=y1; a<y1+h; a++){
            if(v[a][x1]==1) return true;
        }
    }
    return false;
}

int bfs(){
    queue<box> q;
    q.push({s1,s2,s1+h-1,s2+w-1,0});
    ch[s1][s2] = true;
    while(!q.empty()){
        y = q.front().y1;
        x = q.front().x1;
        yy = q.front().y2;
        xx = q.front().x2;
        g = q.front().cnt;
        q.pop();
        if(y==f1&&x==f2){
            return g;
        }
        for(int i=0; i<4; i++){
            ny = y+my[i];
            nx = x+mx[i];
            nyy = yy+my[i];
            nxx = xx+mx[i];
            if(ny<1||ny>n||nx<1||nx>m) continue;
            if(nyy<1||nyy>n||nxx<1||nxx>m) continue;
            if(ch[ny][nx]||v[ny][nx]==1) continue;
            if(canwego(ny,nx,nyy,nxx,i)) continue;
            ch[ny][nx]= true;
            q.push({ny,nx,nyy,nxx,g+1});
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    v.resize(n+1,vector<int>(m+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> v[i][j];
        }
    }
    cin >> h >> w >> s1 >> s2 >> f1 >> f2;
    cout << bfs() << "\n";
    return 0;
}
