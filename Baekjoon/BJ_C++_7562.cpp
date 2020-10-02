#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int tc = 0, len = 0;
int ch[300][300];
int my[8] = {2,1,-1,-2,-2,-1,1,2}, mx[8] = {1,2,2,1,-1,-2,-2,-1};

void bfs(){
    int y = 0 , x = 0;
    int gy = 0, gx = 0;
    cin >> len;
    cin >> y >> x;
    cin >> gy >> gx;
    queue<pair<int, pair<int,int>>> q;
    ch[y][x] = 0;
    q.push(make_pair(0,make_pair(y,x)));
    while(!q.empty()){
        int ty = q.front().second.first;
        int tx = q.front().second.second;
        int num = q.front().first;
        q.pop();
        if(ty==gy&&tx==gx){
            cout << num << "\n";
            return;
        }
        for(int i=0; i<8; i++){
            int ny = ty+my[i];
            int nx = tx+mx[i];
            int nn = num + 1;
            if(ny>=0&&ny<len&&nx>=0&&nx<len){
                if(ch[ny][nx]==0){
                    ch[ny][nx] = nn;
                    q.push(make_pair(nn,make_pair(ny,nx)));
                }
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tc;
    while(tc>0){
        bfs();
        memset(ch,0,sizeof(ch));
        tc--;
    }
    return 0;
}
