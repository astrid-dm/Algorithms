// The problem link : https://www.acmicpc.net/problem/4485
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 987654321
using namespace std;

int c = 1, t, y, x, ny, nx, my[]={0,1,0,-1}, mx[]={1,0,-1,0};

int dijkstra(int &n, vector<vector<int>> &v){
    vector<vector<int>> zelda(n,vector<int>(n,MAX));
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    zelda[0][0] = v[0][0];
    pq.push({0,0});
    while(!pq.empty()){
        y = pq.top().first;
        x = pq.top().second;
        pq.pop();
        for(int i=0; i<4; i++){
            ny = y+my[i];
            nx = x+mx[i];
            if(ny<0||ny>n-1||nx<0||nx>n-1) continue;
            if(zelda[ny][nx]>zelda[y][x]+v[ny][nx]){
                zelda[ny][nx] = zelda[y][x]+v[ny][nx];
                pq.push({ny,nx});
            }
        }
    }
    return zelda[n-1][n-1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(true){
        int n = 0;
        cin >> n;
        if(n==0) break;
        vector<vector<int>> v(n,vector<int>(n,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cin >> v[i][j];
        }
        cout << "Problem" << " " << c << ":" << " " << dijkstra(n,v) << "\n";
        c++;
    }
    return 0;
}
