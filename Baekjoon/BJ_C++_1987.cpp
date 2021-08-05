// The problem link : https://www.acmicpc.net/problem/1987
#include <iostream>
#include <algorithm>
using namespace std;

int r, c, mx[]={1,-1,0,0}, my[]={0,0,1,-1}, ans = 0;
char v[20][20];
bool abc[26];

void move(int y, int x, int cnt){
    if(cnt>ans) ans = cnt;
    for(int i=0; i<4; i++){
        int ny = y+my[i];
        int nx = x+mx[i];
        if(ny<0||ny>=r||nx<0||nx>=c||abc[v[ny][nx]-'A']) continue;
        abc[v[ny][nx]-'A'] = true;
        move(ny,nx,cnt+1);
        abc[v[ny][nx]-'A'] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) cin >> v[i][j];
    }
    abc[v[0][0]-'A'] = true;
    move(0,0,1);
    cout << ans << "\n";
    return 0;
}
