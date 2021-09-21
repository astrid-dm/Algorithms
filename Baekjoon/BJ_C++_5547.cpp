// The problem link : https://www.acmicpc.net/problem/5547
// The result : 2192KB, 0ms
#include <iostream>
#include <algorithm>
using namespace std;

int w=0, h=0, arr[102][102], temp[102][102], dy[]={0,1,0,-1}, dx[]={1,0,-1,0}, ans = 0;
int ny1[]={-1,-1,0,0,1,1}, nx1[]={0,1,-1,1,0,1}, nx2[]={-1,0,-1,1,-1,0}, my, mx;
bool ch[102][102];

void go(int y, int x, int way){
    if(way==1){
        for(int i=0; i<6; i++){
            my = y+ny1[i];
            mx = x+nx1[i];
            if(my<1||my>h||mx<1||mx>w) continue;
            if(arr[my][mx]==0&&!ch[my][mx]){
                ch[my][mx] = true;
                go(my,mx,my%2);
            }
        }
    }else{
        for(int i=0; i<6; i++){
            my = y+ny1[i];
            mx = x+nx2[i];
            if(my<1||my>h||mx<1||mx>w) continue;
            if(arr[my][mx]==0&&!ch[my][mx]){
                ch[my][mx] = true;
                go(my,mx,my%2);
            }
        }
    }
}

void count(int y, int x, int way){
    int num = 0;
    if(way==1){
        for(int i=0; i<6; i++){
            my = y+ny1[i];
            mx = x+nx1[i];
            if(my<1||my>h||mx<1||mx>w) num++;
            else if(arr[my][mx]==0&&ch[my][mx]) num++;
        }
    }else{
        for(int i=0; i<6; i++){
            my = y+ny1[i];
            mx = x+nx2[i];
            if(my<1||my>h||mx<1||mx>w) num++;
            else if(arr[my][mx]==0&&ch[my][mx]) num++;
        }
    }
    temp[y][x] = num;
}

void check(){
    for(int i=1; i<=h; i++){
        if(arr[i][1]==0&&!ch[i][1]){
            ch[i][1] = true;
            go(i,1,i%2);
        }
        if(arr[i][w]==0&&!ch[i][w]){
            ch[i][w] = true;
            go(i,w,i%2);
        }
    }
    for(int i=1; i<=w; i++){
        if(arr[1][i]==0&&!ch[1][i]){
            ch[1][i] = true;
            go(1,i,1);
        }
        if(arr[h][i]==0&&!ch[h][i]){
            ch[h][i] = true;
            go(h,i,h%2);
        }
    }
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(arr[i][j]==1){
                count(i,j,i%2);
                ans += temp[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> w >> h;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++) cin >> arr[i][j];
    }
    check();
    cout << ans << "\n";
    return 0;
}
