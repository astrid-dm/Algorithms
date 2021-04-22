#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 20
using namespace std;

int n,m,x,y,k,arr[MAX][MAX], dice[7] = {0,}, mx[] = {0,0,-1,1}, my[] = {1,-1,0,0}, temp; // x - y가 기존이랑 반대!

void go(int dir){
    dir--;
    x+=mx[dir];
    y+=my[dir];
    if(x<0||x>=n||y<0||y>=m){
        x-=mx[dir];
        y-=my[dir];
        return;
    }
    dir++;
    if(dir==1){ // 동
        temp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = temp;
    }
    else if(dir==2){ // 서
        temp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = temp;
    }
    else if(dir==3){ // 북
        temp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
    }
    else{ // 남
        temp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = temp;
    }
    if(arr[x][y]==0) arr[x][y] = dice[6];
    else {dice[6] = arr[x][y]; arr[x][y] = 0;}
    cout << dice[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x >> y >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> arr[i][j];
    }
    vector<int> v(k);
    for(int i=0; i<k; i++) cin >> v[i];
    for(int i=0; i<k; i++){
        go(v[i]);
    }
    return 0;
}
