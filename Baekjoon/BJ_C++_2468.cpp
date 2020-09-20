#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n = 0, maxi = 0, temp = 0, cnt = 0, nx=0, ny=0;
int v[100][100];
bool check[100][100] = {false,};
int mx[4] = {1,0,-1,0}; //위 아래 좌 우 도표
int my[4] = {0,1,0,-1};

bool track(int y, int x, int h){
    if(y>=n||y<0||x>=n||x<0||v[y][x]<=h||check[y][x]) return false;
    return true;
}

void dfs(int y, int x, int h){
    check[y][x] = true;
    for(int i=0; i<4; i++){
        ny = y+my[i];
        nx = x+mx[i];
        if(track(ny,nx,h)==true){
            dfs(ny,nx,h);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;   
    int h = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> h;
            v[i][j] = h;
            if(h>maxi) maxi = h; //최대치로 오는 비의 양을 기록
        }
    }
    h = 0;    
    while(h<=maxi){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(v[i][j]>h&&check[i][j]==false){
                    dfs(i,j,h);
                    temp++;
                }
            }
        }
        if(temp>cnt) cnt = temp;
        memset(check,false,sizeof(check));
        temp = 0;
        h++;
    }
    cout << cnt << "\n";
    return 0;
}
