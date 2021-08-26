// The problem link : https://www.acmicpc.net/problem/20056
// 2744KB, 12ms
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N,M,K;
pair<int,int> blow[] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
struct fire{
    int r; // 행
    int c; // 열
    int m; // 질량 
    int s; // 속도
    int d; // 방향
};
struct done{
    int m; // 질량
    int s; // 속도
    int d; // 방향, -1로 초기화
};
queue<fire> q;
vector<done> vc[51][51];

void input(){
    cin >> N >> M >> K;
    for(int i=0; i<M; i++){
        int r=0,c=0,m=0,s=0,d=0;
        cin >> r >> c >> m >> s >> d;
        q.push({r,c,m,s,d});
    }
}

void move(){
    while(!q.empty()){
        fire f = q.front();
        q.pop();
        int y = f.r;
        int x = f.c;
        int mm = f.m;
        int ss = f.s;
        int dd = f.d; // 행, 열
        y += (blow[dd].first * ss); 
        x += (blow[dd].second * ss);
        if(y<0) y=(N-abs(y%N))%N;
        else y%=N;
        if(x<0) x=(N-abs(x%N))%N;
        else x%=N;
        if(y==0) y=N; if(x==0) x=N;
        vc[y][x].push_back({mm,ss,dd});
    }
}

void shoot(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(vc[i][j].size()==1){
                q.push({i,j,vc[i][j].front().m,vc[i][j].front().s,vc[i][j].front().d});
                vc[i][j].clear();
            }
            else if(vc[i][j].size()>=2){
                int nn = vc[i][j].size();
                int mm = 0;
                int ss = 0;
                int dd = -1; // -2면 홀수로 간다
                for(int x=0; x<vc[i][j].size(); x++){
                    mm += vc[i][j][x].m;
                    ss += vc[i][j][x].s;
                    if(dd==-1) dd = vc[i][j][x].d;
                    else if(dd>=0){
                        if(dd%2!=vc[i][j][x].d%2) dd=-2;
                    }
                }
                vc[i][j].clear();
                if(mm/5<=0) continue;
                if(dd>=0){
                    for(int x=0; x<8; x+=2) q.push({i,j,mm/5,ss/nn,x});
                }else{
                    for(int x=1; x<8; x+=2) q.push({i,j,mm/5,ss/nn,x});
                }
            }
        }
    }
}

int answer(){
    int ans = 0;
    while(!q.empty()){
        int temp = q.front().m;
        q.pop();
        ans+=temp;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    while(K--){
        move();
        shoot();
    }
    cout << answer() << "\n";
    return 0;
}
