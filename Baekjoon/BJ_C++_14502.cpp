#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,arr[9][9],temp[9][9],my[] = {1,0,-1,0}, mx[] = {0,1,0,-1}, ans,cnt;

int bfs(){
    int safe = 0;
    queue<pair<int,int>> q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            temp[i][j] = arr[i][j];
            if(temp[i][j]==2) q.push({i,j});
        }
    }
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y+my[i];
            int nx = x+mx[i];
            if(ny>=1&&ny<=n&&nx>=1&&nx<=m&&temp[ny][nx]==0){
                temp[ny][nx]=2;
                q.push({ny,nx});
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(temp[i][j]==0) safe++;
        }
    }
    return safe;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cin >> arr[i][j];
    }
    for(int y1=1; y1<=n; y1++){
        for(int x1=1; x1<=m; x1++){
            if(arr[y1][x1]!=0) continue;
            for(int y2=1; y2<=n; y2++){
                for(int x2=1; x2<=m; x2++){
                    if(arr[y2][x2]!=0||(y1==y2&&x1==x2)) continue;
                    for(int y3=1; y3<=n; y3++){
                        for(int x3=1; x3<=m; x3++){
                            if(arr[y3][x3]!=0) continue;
                            if(y1==y3&&x1==x3) continue;
                            if(y2==y3&&x2==x3) continue;
                            arr[y1][x1] = 1;
                            arr[y2][x2] = 1;
                            arr[y3][x3] = 1;
                            cnt = bfs();
                            if(cnt>ans) ans = cnt;
                            arr[y1][x1] = 0;
                            arr[y2][x2] = 0;
                            arr[y3][x3] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
