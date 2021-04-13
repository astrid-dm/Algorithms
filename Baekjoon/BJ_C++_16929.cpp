#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

bool ch[MAX][MAX];
int n,m,sy,sx,my[] = {0,0,1,-1}, mx[] = {1,-1,0,0}, ny, nx;
vector<vector<char>> v(50,vector<char>(50,0));

void dfs(int y, int x, int num){
    ch[y][x] = true;
    for(int i=0; i<4; i++){
        ny = y+my[i];
        nx = x+mx[i];
        if(ny>=0&&ny<n&&nx>=0&&nx<m&&v[y][x]==v[ny][nx]&&!ch[ny][nx]) dfs(ny,nx,num+1);
        else if(sy==ny&&sx==nx&&num>=4){
            cout << "Yes" << "\n";
            exit(0);
        }
    }
    ch[y][x] = false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
            ch[i][j] = false;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!ch[i][j]){
                sy = i, sx = j;
                dfs(i,j,1);
                ch[i][j] = true;
            }
        }
    }
    cout << "No" << "\n";
    return 0;
}
