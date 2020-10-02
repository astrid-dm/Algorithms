#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n = 0, m = 0, ny = 0, nx = 0;
int arr[1002][1002], my[4] = {1,0,-1,0}, mx[4] = {0,1,0,-1};
bool ch[1002][1002][2]; // 벽을 뚫고 방문한 경험과, 벽을 뚫지않고 방문한 경험을 나눔

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> c;
            arr[i][j] = c - 48;
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push(make_pair(make_pair(1,1),make_pair(0,1))); //현재 위치 한 쌍 + 벽을 부순 횟수 + 누적 이동 횟수
    ch[1][1][0] = true;
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int wall = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if(y==n&&x==m){
            cout << cnt << "\n";
            exit(0);
        }

        for(int i=0; i<4; i++){
            ny = y+my[i];
            nx = x+mx[i];

            if(ny>0&&ny<=n&&nx>0&&nx<=m){
                if(arr[ny][nx]==1 && wall==0){ // 다음 경로가 벽이지만 아직 한 번도 벽을 안뚫었다
                    ch[ny][nx][wall+1] = true;
                    q.push(make_pair(make_pair(ny,nx),make_pair(wall+1,cnt+1)));
                }
                else if(arr[ny][nx]==0&&!ch[ny][nx][wall]){ //다음 경로가 통로고 해당 위치를 방문한 적이 없다
                    ch[ny][nx][wall] = true;
                    q.push(make_pair(make_pair(ny,nx),make_pair(wall,cnt+1)));
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}
