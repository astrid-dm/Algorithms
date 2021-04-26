#include <iostream>
#define MAX 101
using namespace std;

int arr[MAX][MAX],n,l, ans = 0;
bool row[MAX][MAX], col[MAX][MAX], ch; // true = 다리 못넣는다

bool possible(int y, int x){
    if(arr[y][x-1]>arr[y][x]){ // 2(x-1),1(x)
        for(int i=x+1; i<x+l; i++){
            if(row[y][i]) return true;
            if(arr[y][x]!=arr[y][i]) return true; // 다리 못넣는다
            else row[y][i] = true;
        }
        if(x+l<=n){
            if(arr[y][x]<arr[y][x+l]) return true;
        }
    }
    else{ // 1(x-1),2(x)
        for(int i=x-2; i>=x-l; i--){
            if(row[y][i]) return true;
            if(arr[y][x-1]!=arr[y][i]) return true;
            else row[y][i] = true;
        }
        if(x-l-1>=1){
            if(arr[y][x-1]<arr[y][x-l-1]) return true;
        }
    }
    return false;
}

bool possible2(int y, int x){ // 2
    if(arr[y-1][x]>arr[y][x]){ // 1 (y)
        for(int i=y+1; i<y+l; i++){
            if(col[y][i]) return true;
            if(arr[y][x]!=arr[i][x]) return true; // 다리 넣기 실패
            else col[i][x] = true;
        }
        if(y+l<=n){
            if(arr[y][x]<arr[y+l][x]) return true;
        }
    }     // 1
    else{ // 2 (y)
        for(int i=y-2; i>=y-l; i--){
            if(col[i][x]) return true;
            if(arr[y-1][x]!=arr[i][x]) return true;
            else col[i][x] = true;
        }
        if(y-l-1>=1){
            if(arr[y-1][x]<arr[y-l-1][x]) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> arr[i][j];
    }
    for(int i=1; i<=n; i++){ // row 
        ch = false;
        for(int j=2; j<=n; j++){
            if(arr[i][j-1]==arr[i][j]) continue;
            else{ // 경사로 넣기
                if(abs(arr[i][j]-arr[i][j-1])!=1) ch = true;
                else ch = possible(i,j);
            }
            if(ch) break;
        }
        if(!ch) ans++;
    }
    for(int i=1; i<=n; i++){ // col
        ch = false;
        for(int j=2; j<=n; j++){
            if(arr[j][i]==arr[j-1][i]) continue;
            else{ // 경사로 넣기
                if(abs(arr[j][i]-arr[j-1][i])!=1) ch = true;
                else ch = possible2(j,i);
            }
            if(ch) break;
        }
        if(!ch) ans++;
    }
    cout << ans << "\n";
    return 0;
}
