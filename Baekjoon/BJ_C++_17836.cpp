#include <iostream>
#include <queue>
using namespace std;

int n=0,m=0,t=0, arr[101][101], ny=0, nx=0;
int my[4] = {1,0,-1,0}, mx[4] = {0,1,0,-1};
bool ch[101][101][2] = {false,};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> q; // 전자는 위치, 후자는 검을 여부와 경과 시간
    q.push(make_pair(make_pair(1,1),make_pair(0,0)));
    ch[1][1][0] = true, ch[1][1][1] = true;
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int s = q.front().second.first; // 검의 여부
        int cnt = q.front().second.second; // 지난 시간
        q.pop();
        if(cnt>t) continue;
        for(int i=0; i<4; i++){
            ny = y+my[i];
            nx = x+mx[i];
            if(ny==n&&nx==m){
                if(cnt+1<=t){
                    cout << cnt + 1 << "\n";
                    exit(0);
                }
            }
            else if(ny>0&&ny<=n&&nx>0&&nx<=m){
                if(s==1){ // 검이 있음
                    if(arr[ny][nx]==1&&!ch[ny][nx][s]){
                        ch[ny][nx][s] = true;
                        q.push(make_pair(make_pair(ny,nx),make_pair(s,cnt+1)));
                    }
                    else if(arr[ny][nx]==0&&!ch[ny][nx][s]){
                        ch[ny][nx][s] = true;
                        q.push(make_pair(make_pair(ny,nx),make_pair(s,cnt+1)));
                    } else continue;
                }
                else{ // 검이 없음
                    if(arr[ny][nx]==1) continue;
                    else if(arr[ny][nx]==0&&!ch[ny][nx][s]){
                        ch[ny][nx][s] = true;
                        q.push(make_pair(make_pair(ny,nx),make_pair(s,cnt+1)));
                    }
                    else if(arr[ny][nx]==2&&!ch[ny][nx][s]){
                        ch[ny][nx][s] = true, ch[ny][nx][1] = true;
                        q.push(make_pair(make_pair(ny,nx),make_pair(1,cnt+1)));
                    } else continue;
                }
            }
        }
    }
    cout << "Fail" << "\n";
   return 0;
}
