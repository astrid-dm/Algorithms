#include <iostream>
using namespace std;

int arr[501][501], dy[] = {0,0,1,-1}, dx[] = {1,-1,0,0}, ans = 0, n=0, m=0;
bool ch[501][501];

void go(int y, int x, int sum, int cnt){
    if(cnt==4){
        if(ans<sum) ans = sum;
        return;
    }
    if(y<1||y>n||x<1||x>m) return;
    if(ch[y][x]) return;
    ch[y][x] = true;
    for(int i=0; i<4; i++){
        go(y+dy[i], x+dx[i], sum+arr[y][x], cnt+1);
    }
    ch[y][x] = false; // DFS일 경우 이 코드가 없다! 고로 이 코드는 Brute Force다!
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            go(i,j,0,0); // 이 과정으로 인해 'ㅜ'를 제외한 나머지 테트리스들의 시뮬레이션이 가능해진다.
            if(j+2<=m){
                int temp = arr[i][j]+arr[i][j+1]+arr[i][j+2];
                if(i-1>=1){
                    int temp2 = temp + arr[i-1][j+1]; // ㅗ 모양
                    if(ans<temp2) ans = temp2;
                }
                if(i+1<=n){
                    int temp2 = temp + arr[i+1][j+1]; // ㅜ 모양
                    if(ans<temp2) ans = temp2;
                } // 참고로 if-else가 아닌 if-if를 작성한 이유는, 한 번에 두 번의 케이스를 모두 테스트하기 위함이다
            }
            if(i+2<=n){
                int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j];
                if(j+1<=m){
                    int temp2 = temp + arr[i+1][j+1]; // ㅏ 모양
                    if(ans<temp2) ans = temp2;
                }
                if(j-1>=1){
                    int temp2 = temp + arr[i+1][j-1]; // ㅓ 모양
                    if(ans<temp2) ans = temp2;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
