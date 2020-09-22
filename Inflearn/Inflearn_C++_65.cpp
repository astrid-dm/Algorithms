#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10][10], ans = 0;
int my[4] = {1,0,-1,0};
int mx[4] = {0,1,0,-1};
bool check[10][10];

bool track(int y, int x){
    if(y<1||y>7||x<1||x>7||check[y][x]||arr[y][x]==1) return false;
    return true;
}

void dfs(int y, int x){
    if(y==7&&x==7){
        ans++;
    }
    else{
        for(int i=0; i<4; i++){
            int ny = y+my[i]; //전역변수가 아닌 지역변수 설정
            int nx = x+mx[i]; //전역변수가 아닌 지역변수 설정
            if(track(ny,nx)){
                check[ny][nx] = true;
                dfs(ny,nx);
                check[ny][nx] = false;
            }
            else continue;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1; i<=7; i++){
        for(int j=1; j<=7; j++){
            cin >> arr[i][j];
            check[i][j] = false;
        }
    }
    check[1][1] = true;
    dfs(1,1);
    cout << ans << "\n";
    return 0;
}
