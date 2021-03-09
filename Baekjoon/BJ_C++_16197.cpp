#include <iostream>
#include <algorithm>
#include <queue>
const int MAX = 21;
using namespace std;

int dy[] = {0,0,1,-1}, dx[] = {1,-1,0,0}, n=0, m=0, temp = 0;
char arr[MAX][MAX];
bool ch[MAX][MAX][MAX][MAX] = {false,};
pair<int,int> coin[2];

struct c{
    int y1,x1;
    int y2,x2;
    int cnt;
};

int sway(int y1, int x1, int y2, int x2){
    if((y1<1||y1>n||x1<1||x1>m)&&(y2<1||y2>n||x2<1||x2>m)) return -1; // 동전 둘다 아웃
    if(y1<1||y1>n||x1<1||x1>m) return 1; // 동전 1개 아웃
    if(y2<1||y2>n||x2<1||x2>m) return 1; // 동전 1개 아웃
    return 0;
}

int bfs(){
    queue<c> q;
    q.push({coin[0].first,coin[0].second,coin[1].first,coin[1].second,0});
    while(!q.empty()){
        c cur = q.front();
        int y1=cur.y1; int x1=cur.x1;
        int y2=cur.y2; int x2=cur.x2;
        int now=cur.cnt;
        ch[y1][x1][y2][x2] = true;
        q.pop();
        for(int i=0; i<4; i++){
            int ny1 = y1+dy[i]; int nx1 = x1+dx[i];
            int ny2 = y2+dy[i]; int nx2 = x2+dx[i];
            if(arr[ny1][nx1]=='#'&&arr[ny2][nx2]=='#') continue; // 벽에 부딪쳤으면 아래 공식은 무시하고 다시 for문으로 복귀
            temp = sway(ny1,nx1,ny2,nx2);
            if(temp==-1) continue;
            if(temp==1){
                if(now+1>10) return -1;
                else return now+1;
            } 
            // 아래부터는 각가 벽에 부딪치는 경우 -> 원래 자리로 되돌려주기
            if(arr[ny1][nx1]=='#') ny1-=dy[i], nx1-=dx[i];
            else if(arr[ny2][nx2]=='#') ny2-=dy[i], nx2-=dx[i];
            if(!ch[ny1][nx1][ny2][nx2]){
                q.push({ny1,nx1,ny2,nx2,now+1});
            }
        }
    }
    return -1;
}

void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
            if(arr[i][j]=='o'){
                coin[temp].first=i, coin[temp].second=j;
                temp++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    input();
    cout << bfs() << "\n";
    return 0;
}
