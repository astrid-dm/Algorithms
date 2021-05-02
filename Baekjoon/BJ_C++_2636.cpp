#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;

int arr[MAX][MAX], h,w,my[] = {-1,0,1,0}, mx[] = {0,1,0,-1}, ny, nx, y, x, cnt = 0, ans = 0, cheese = 0;
bool ch[MAX][MAX], visited[MAX][MAX], done;

void outofcheese(int yy, int xx){
    visited[yy][xx] = true;
    for(int i=0; i<4; i++){
        ny = yy+my[i];
        nx = xx+mx[i];
        if(ny>0&&ny<=h&&nx>0&&nx<=w&&!visited[ny][nx]&&arr[ny][nx]==0) outofcheese(ny,nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> h >> w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++) cin >> arr[i][j];
    }
    while(true){
        done = false;
        cheese = 0;
        outofcheese(1,1);
        queue<pair<int,int>> q;
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                if(arr[i][j]==0&&visited[i][j]==true){
                    y=i;
                    x=j;
                    for(int i=0; i<4; i++){
                        ny = y+my[i];
                        nx = x+mx[i];
                        if(ny>=1&&ny<=h&&nx>=1&&nx<=w&&arr[ny][nx]==1&&!ch[ny][nx]){
                            ch[ny][nx] = true;
                            q.push({ny,nx});
                        }
                    }
                }
            }
        }
        while(!q.empty()){
            y = q.front().first;
            x = q.front().second;
            arr[y][x] = 0;
            cheese++;
            done = true;
            q.pop();
        }
        if(done){
            cnt++;
            ans = cheese;
        }
        else break;
        memset(ch,false,sizeof(ch));
        memset(visited,false,sizeof(visited));
    }
    cout << cnt << "\n" << ans << "\n";
    return 0;
}
