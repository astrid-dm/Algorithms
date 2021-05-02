#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[51][51], my[] = {-1,0,1,0}, mx[] = {0,-1,0,1}, y, x, ny, nx, n, l, r, ans = 0, people = 0, country = 0;
bool ch[51][51], done;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l >> r;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> arr[i][j];
    }
    queue<pair<int,int>> q;
    queue<pair<int,int>> q2;
    while(true){
        done = false;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(ch[i][j]) continue;
                q.push({i,j});
                q2.push({i,j});
                ch[i][j] = true;
                people = arr[i][j];
                country = 1;
                while(!q.empty()){
                    y = q.front().first;
                    x = q.front().second;
                    for(int i=0; i<4; i++){
                        ny = y + my[i];
                        nx = x + mx[i];
                        if(ny>=1&&ny<=n&&nx>=1&&nx<=n&&!ch[ny][nx]&&abs(arr[y][x]-arr[ny][nx])>=l&&abs(arr[y][x]-arr[ny][nx])<=r){
                            ch[ny][nx] = true;
                            q.push({ny,nx});
                            q2.push({ny,nx});
                            done = true;
                            people += arr[ny][nx];
                            country++;
                        }
                    }
                    q.pop();
                }
                if(q2.size()!=1){
                    while(!q2.empty()){
                        y = q2.front().first;
                        x = q2.front().second;
                        arr[y][x] = people / country;
                        q2.pop();
                    }
                }
                else q2.pop();
            }
        }
        memset(ch,false,sizeof(ch));
        if(done) ans++;
        else break;
    }
    cout << ans << "\n";
    return 0;
}
