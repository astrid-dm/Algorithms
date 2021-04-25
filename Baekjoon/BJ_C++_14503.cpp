#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;
// 북 동 남 서
int arr[MAX][MAX], ans=0, my[] = {-1,0,1,0}, mx[] = {0,1,0,-1}, y,x,ny,nx,m,n,dir,bdir;
bool ch[MAX][MAX];

bool go4(int y, int x){
    for(int i=0; i<4; i++){
        ny = y+my[i];
        nx = x+mx[i];
        if(!ch[ny][nx]) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> y >> x >> dir;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j]; // 빈칸 = 0, 벽 = 1
            if(arr[i][j]==1) ch[i][j] = true;
        }
    }
    while(true){
        if(!ch[y][x]){
            ans++;
            ch[y][x] = true;
        }
        bool go = go4(y,x);
        if(go){ // 네 방향 중 하나라도 칸이 있다면 회전부터 하기
            dir-=1;
            if(dir<0) dir = 3;
            ny = y+my[dir];
            nx = x+mx[dir];
            if(!ch[ny][nx]){
                y = ny;
                x = nx;
            }
            else;
        }
        else{ // 네 방향 모두 청소가 끝났다 -> 후진이 되냐 안되냐로 따지기
            if(dir<2) bdir=dir+2;
            else bdir=dir-2;
            ny = y+my[bdir];
            nx = x+mx[bdir];
            if(arr[ny][nx]==1) break;
            else{
                y = ny;
                x = nx;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
