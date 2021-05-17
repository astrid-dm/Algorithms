#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, ans=-1, my[]={-2,-2,0,2,2,0}, mx[]={-1,1,2,1,-1,-2}, ny, nx, y1, x1, y2, x2, cnt;
bool ch[200][200];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> y1 >> x1 >> y2 >> x2;
    queue<pair<pair<int,int>,int>> q;
    q.push({{y1,x1},0});
    ch[y1][x1] = true;
    while(!q.empty()){
        y1 = q.front().first.first;
        x1 = q.front().first.second;
        cnt = q.front().second;
        q.pop();
        if(y1==y2&&x1==x2){
            cout << cnt << "\n";
            exit(0);
        }
        for(int i=0; i<6; i++){
            ny = y1+my[i];
            nx = x1+mx[i];
            if(ny>=0&&ny<n&&nx>=0&&nx<n&&!ch[ny][nx]){
                ch[ny][nx] = true;
                q.push({{ny,nx},cnt+1});
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
