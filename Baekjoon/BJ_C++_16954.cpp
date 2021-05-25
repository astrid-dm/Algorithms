// The problem link : https://www.acmicpc.net/problem/16954
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int y,x,m,ny,nx,my[]={1,1,1,0,0,0,-1,-1,-1},mx[]={-1,0,1,-1,0,1,-1,0,1},nm;
char arr[9][9];
bool ch[9][9][9];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<pair<int,int>> wall;
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++) cin >> arr[i][j];
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{8,1},0});
    ch[8][1][0] = true;
    while(!q.empty()){
        y = q.front().first.first;
        x = q.front().first.second;
        m = q.front().second;
        if(y==1&&x==8){
            cout << 1 << "\n";
            exit(0);
        }
        q.pop();
        for(int i=0; i<9; i++){
            ny = y+my[i];
            nx = x+mx[i];
            nm = min(m+1,8);
            if(ny>=1&&ny<=8&&nx>=1&&nx<=8&&!ch[ny][nx][nm]){
                if(arr[ny-nm+1][nx]=='#') continue; // 이동하고나서 벽이 내려오는지
                if(arr[ny-nm][nx]=='#') continue; // 이동하려는 위치가 벽인지
                ch[ny][nx][nm] = true; // 위의 조건들이 아닐 경우 지나갈 수 있는 경로
                q.push({{ny,nx},nm});
            }
        }
    }
    cout << 0 << "\n";
    return 0;
}
