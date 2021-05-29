// The problem link : https://programmers.co.kr/learn/courses/30/lessons/1829
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int mm, nn, big=0, area=0, y, x, ny, nx, my[]={0,1,0,-1}, mx[]={1,0,-1,0};
bool ch[101][101];

void dfs(int a, int b, vector<vector<int>> & picture){
    int num = 1;
    queue<pair<int,int>> q;
    q.push({a,b});
    ch[a][b] = true;
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            ny = y+my[i];
            nx = x+mx[i];
            if(ny>=0&&ny<mm&&nx>=0&&nx<nn&&!ch[ny][nx]&&picture[a][b]==picture[ny][nx]){
                ch[ny][nx] = true;
                num++;
                q.push({ny,nx});
            }
        }
    }
    if(area<num) area = num;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer;
    mm=m, nn=n, big=0, area=0, y=0, x=0, ny=0, nx=0;
    memset(ch,false,sizeof(ch));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!ch[i][j]&&picture[i][j]!=0){
                big++;
                dfs(i,j,picture);
            }
        }
    }
    answer.push_back(big);
    answer.push_back(area);
    return answer;
}
