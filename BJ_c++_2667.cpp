#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n = 0, arr[25][25], res = 0, cnt=0, y2=0,x2=0;
bool check[25][25] = {false,};
int ym[4] = {1,0,-1,0}; //시계방향으로 주택의 위치 파악
int xm[4] = {0,1,0,-1};
vector<int> v;
char c;

bool track(int y, int x){
    if(y>=n||x>=n||y<0||x<0) return false;
    if(check[y][x]||arr[y][x]==0) return false;
    return true;
}

void dfs(int y, int x){
    cnt++;
    check[y][x]=true;
    for(int i=0; i<4; i++){
        y2=y+ym[i];
        x2=x+xm[i];
        if(track(y2,x2)==true) dfs(y2,x2);
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c;
            arr[i][j] = c-48;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j]==false&&arr[i][j]==1){
                cnt = 0;
                dfs(i,j);
                res++;
                v.push_back(cnt);
            }
        }
    }
    cout << res << "\n";
    if(!v.size()==0){
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++) cout << v[i] << "\n";
    }

    return 0;
}
