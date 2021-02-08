#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct mint{
    int y;
    int x;
    int checked;
};

int n=0,m=0,h=0,ans=0, arr[11][11];
vector<mint> v;
pair<int,int> start;

void dfs(int y, int x, int cnt, int health){
    if(cnt>ans){
        if(abs(y-start.first)+abs(x-start.second)<=health) ans = cnt;
    }
    if(health<=0||cnt==v.size()) return;
    for(int i=0; i<v.size(); i++){
        int newdis = abs(y-v[i].y)+abs(x-v[i].x);
        if(v[i].checked==0&&newdis<=health){
            v[i].checked=1;
            dfs(v[i].y,v[i].x,cnt+1,health-newdis+h);
            v[i].checked=0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1) start.first = i, start.second = j;
            else if(arr[i][j]==2) v.push_back({i,j,0});
        }
    }
    dfs(start.first, start.second, 0, m);
    cout << ans << "\n";
   return 0;
}
