#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n,ate,s=2,y,x,nm,ny,nx,my[]={1,0,-1,0},mx[]={0,1,0,-1},ans=0,arr[21][21];
bool ch[21][21];

typedef pair<int,pair<int,int>> fish;
typedef pair<int,pair<int,int>> shark;

bool bfs(){
    queue<shark> q;
    vector<fish> v;
    int info[] = {500,500,500};
    q.push({0,{y,x}});
    ch[y][x] = true;
    while(!q.empty()){
        int mm = q.front().first;
        int yy = q.front().second.first;
        int xx = q.front().second.second;
        q.pop();
        for(int i=0; i<4; i++){
            nm = mm +1;
            ny = yy+my[i];
            nx = xx+mx[i];
            if(ny>=1&&ny<=n&&nx>=1&&nx<=n&&!ch[ny][nx]&&arr[ny][nx]<=s){ // 조건 중요
                ch[ny][nx] = true;
                q.push({nm,{ny,nx}});
                if(arr[ny][nx]>0&&arr[ny][nx]<s) v.push_back({nm,{ny,nx}});
            }
        }
    }
    if(v.size()==0) return false;
    else{
        for(int i=0; i<v.size(); i++){
            if(v[i].first<info[0]){ // 보다 단거리에 있다
                info[0] = v[i].first;
                info[1] = v[i].second.first;
                info[2] = v[i].second.second;
            }
            else if(v[i].first==info[0]){ // 거리가 같다면
                if(info[1]<v[i].second.first) continue;
                else if(info[1]>v[i].second.first){ // y축이 더 위쪽에 있는걸로 갱신해준다
                    info[0] = v[i].first;
                    info[1] = v[i].second.first;
                    info[2] = v[i].second.second;
                }
                else if(info[1]==v[i].second.first){ // 만약 y축마져도 같다면
                    if(info[2]>v[i].second.second){ // x축이 더 왼쪽에 있는걸로 갱신해준다
                        info[0] = v[i].first;
                        info[1] = v[i].second.first;
                        info[2] = v[i].second.second;
                    }
                }
            }
        }
        ans += info[0];
        arr[info[1]][info[2]] = 0;
        y = info[1];
        x = info[2];
        ate++;
        if(ate==s){
            s++;
            ate = 0;
        }
        memset(ch,false,sizeof(ch)); // 막판에 방문여부 초기화 잊지말기
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            if(arr[i][j]==9){
                y=i;
                x=j;
                arr[i][j] = 0; // 중요
            }
        }
    }
    while(true){ // 먹을 수 있는 물고기중 가장 최단거리 물고기를 판단해서 잡아먹는다.
        if(!bfs()) break;
    }
    cout << ans << "\n";
    return 0;
}
