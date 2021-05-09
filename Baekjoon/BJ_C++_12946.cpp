#include <iostream>
#include <cstring>
using namespace std;

int n, my[] = {-1,-1,0,1,1,0}, mx[] = {0,1,1,0,-1,-1}, color[51][51], ny, nx, y, x, ans = 0;
char arr[51][51];

void dfs(int y, int x, int c){
    color[y][x] = c;
    ans = max(ans,1);
    for(int i=0; i<6; i++){
        ny = y+my[i];
        nx = x+mx[i];
        if(arr[ny][nx]=='X'){
            if(color[ny][nx]==-1){
                dfs(ny,nx,1-c);
                ans = max(ans,2);
            }
            else if(color[ny][nx]==c){
                ans = max(ans,3);
                cout << 3 << "\n";
                exit(0);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    memset(color,-1,sizeof(color));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]=='X' && color[i][j]==-1) dfs(i,j,0);
        }
    }
    cout << ans << "\n";
    return 0;
}
