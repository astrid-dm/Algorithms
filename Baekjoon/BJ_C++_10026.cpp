#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n = 0, nx = 0, ny = 0,ncb = 0, cb = 0;
char arr[101][101], temp;
bool check[100][100];
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};

bool cb_track(int y, int x, char c){
   if(y<0||y>n||x<0||x>n||check[y][x]) return false; // 범위 초과 혹은 방문 경험이 있으면 false
   else{
       if(arr[y][x]==c) return true;
       else if(c=='R'&&arr[y][x]=='G') return true;
       else if(c=='G'&&arr[y][x]=='R') return true;
   } 
   return false;
}

void cb_dfs(int y, int x){
    check[y][x] = true;
    temp = arr[y][x];
    for(int i=0; i<4; i++){
        ny = y+my[i];
        nx = x+mx[i];
        if(cb_track(ny,nx,temp)){
            cb_dfs(ny,nx);
        }
        else continue;
    }
}

bool ncb_track(int y, int x, char c){
    if(y<0||y>n||x<0||x>n||check[y][x]) return false; // 범위 초과 혹은 방문 경험이 있으면 false
    else if(arr[y][x]==c) return true;
    return false;
}

void ncb_dfs(int y, int x){
    check[y][x] = true;
    temp = arr[y][x];
    for(int i=0; i<4; i++){
        ny = y+my[i];
        nx = x+mx[i];
        if(ncb_track(ny,nx,temp)){
            ncb_dfs(ny,nx);
        }
        else continue;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!check[i][j]){
                ncb_dfs(i,j);
                ncb++;
            }
        }
    }
    memset(check,false,sizeof(check));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!check[i][j]){
                cb_dfs(i,j);
                cb++;
            }
        }
    }
    cout << ncb << " " << cb << "\n";
    return 0;
}
