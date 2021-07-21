// The problem : https://www.acmicpc.net/problem/2234
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 51

using namespace std;
// m = 세로, n = 가로
int m,n,ny,nx,y,x,my[]={0,-1,0,1},mx[]={-1,0,1,0},arr[MAX][MAX],ch[MAX][MAX],map[MAX][MAX],color=0, num=0, temp, largeroom, largeroom2;
struct pa{
    int yy;
    int xx;
};
queue<pa> q;

void input(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) cin >> arr[i][j];
    }
}

void bfs(int y, int x){
    num++;
    ch[y][x] = color;
    q.push({y,x});
    for(int k=0; k<4; k++){
        ny=y+my[k];
        nx=x+mx[k];
        if(ny<0||ny>=m||nx<0||nx>=n) continue;
        if(ch[ny][nx]!=0) continue; // 이미 방문함
        temp = 1<<k;
        if(arr[y][x]&temp) continue; // 벽
        bfs(ny,nx);
    }
}

void firstAndSecond(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(ch[i][j]==0){
                color++;
                num = 1; // 방의 넓이
                ch[i][j] = color;
                q.push({i,j});
                for(int k=0; k<4; k++){
                    y=i+my[k];
                    x=j+mx[k];
                    if(y<0||y>=m||x<0||x>=n) continue;
                    if(ch[y][x]!=0) continue; // 이미 방문함
                    temp = 1<<k;
                    if(arr[i][j]&temp) continue; // 벽
                    bfs(y,x);
                }
                while(!q.empty()){
                    y = q.front().yy;
                    x = q.front().xx;
                    q.pop();
                    map[y][x] = num;
                }
                if(largeroom<num) largeroom = num;
            }
        }
    }

}

void third(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]!=-1){
                arr[i][j]=-1;
                for(int k=0; k<4; k++){
                    y=i+my[k];
                    x=j+mx[k];
                    if(y<0||y>=m||x<0||x>=n) continue;
                    if(arr[y][x]==-1) continue; // 이미 방문함
                    temp = 1<<k;
                    if(arr[i][j]&temp){
                        if(map[y][x]+map[i][j]>largeroom2&&ch[i][j]!=ch[y][x]) largeroom2 = map[y][x]+map[i][j];
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    firstAndSecond();
    third();
    cout << color << "\n" << largeroom << "\n" << largeroom2 << "\n";
    return 0;
}
