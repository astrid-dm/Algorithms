#include <iostream>
#define MAX 101
using namespace std;

int arr[MAX][MAX], my[] = {1,0,-1,0}, mx[] = {0,1,0,-1}, ny, nx, y, x, n, m, temp, ans = 0;

void solve(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            temp = 2*(1+arr[i][j]+arr[i][j]);
            y = i;
            x = j;
            for(int i=0; i<4; i++){
                ny = y+my[i];
                nx = x+mx[i];
                if(ny>=1&&ny<=n&&nx>=1&&nx<=m){
                    if(arr[y][x]>=arr[ny][nx]) temp -= arr[ny][nx];
                    else temp -= arr[y][x];
                }
            }
            ans+=temp;
        }
    }
}

void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cin >> arr[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    solve();
    cout << ans << "\n";
    return 0;
}
