// The problem link : https://www.acmicpc.net/problem/16946
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n,m,my[]={1,0,-1,0},mx[]={0,1,0,-1},ny,nx,y,x,cnt,num=1,label[1001][1001],v[1001][1001];
char temp;
bool ch[1001][1001];

void bfs(int a, int b, int labeling){
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;
    cnt = 1;
    label[a][b] = labeling;
    q1.push({a,b});
    q2.push({a,b});
    ch[a][b] = true;
    while(!q1.empty()){
        y = q1.front().first;
        x = q1.front().second;
        q1.pop();
        for(int i=0; i<4; i++){
            ny = y+my[i];
            nx = x+mx[i];
            if(ny>=1&&ny<=n&&nx>=1&&nx<=m&&!ch[ny][nx]&&v[ny][nx]==0){
                ch[ny][nx] = true;
                cnt++;
                label[ny][nx] = labeling;
                q1.push({ny,nx});
                q2.push({ny,nx});
            }
        }
    }
    while(!q2.empty()){
        y = q2.front().first;
        x = q2.front().second;
        q2.pop();
        v[y][x] = cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> temp;
            v[i][j] = temp-'0';
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(v[i][j]==0&&!ch[i][j]) bfs(i,j,num++);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!ch[i][j]){ //방문하지 않은 곳 = 벽
                vector<int> arr;
                cnt = 1;
                for(int x=0; x<4; x++){
                    bool visited = false;
                    ny = i+my[x];
                    nx = j+mx[x];
                    if(ny>=1&&ny<=n&&nx>=1&&nx<=m&&ch[ny][nx]){
                        for(int z=0; z<arr.size(); z++){
                            if(arr[z]==label[ny][nx]) visited = true;
                        }
                        if(!visited){
                            arr.push_back(label[ny][nx]);
                            cnt += v[ny][nx];
                        }
                    }
                }
                v[i][j] = cnt%10;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(ch[i][j]) cout << 0;
            else cout << v[i][j];
        }
        cout << "\n";
    }
    return 0;
}
