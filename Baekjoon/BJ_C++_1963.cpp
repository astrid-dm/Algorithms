// The problem link : https://www.acmicpc.net/problem/1963
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 10000
using namespace std;

int n;
bool prime[MAX], visited[MAX];
struct tc{
    int a,b;
};
void separate_prime(){
    prime[2] = false, prime[3] = false, prime[5] = false, prime[7] = false;
    for(int i=2; i<MAX; i++){
        if(!prime[i]){
            for(int j=i+i; j<MAX; j+=i){
                prime[j] = true; 
            }
        }
    }
}

int bfs(int from, int to){
    queue<tc> q;
    q.push({0,from});
    while(!q.empty()){ // prime이 false여야 소수
        int cnt = q.front().a;
        int now = q.front().b;
        if(now==to) return cnt;
        q.pop();
        if(now%10!=to%10&&now/10==to/10) return cnt+1; // 정답에서 첫 번째 자리만 다름
        else if((now/10)%10!=(to/10)%10&&now%10==to%10&&now/100==to/100) return cnt+1; // 두 번째 자리
        else if((now/100)%10!=(to/100)%10&&now/1000==to/1000&&now%100==to%100) return cnt+1; // 세 번째 자리
        else if(now/1000!=to/1000&&now%1000==to%1000) return cnt+1; // 네 번째
        for(int i=1001; i<MAX; i++){
            if(!prime[i]&&!visited[i]&&now%10!=i%10&&now/10==i/10){ // 해당 소수와 첫 번째 자리만 다름
                visited[i] = true;
                q.push({cnt+1,i});
            }
            else if(!prime[i]&&!visited[i]&&(now/10)%10!=(i/10)%10&&now%10==i%10&&now/100==i/100){ // 두 번째 자리
                visited[i] = true;
                q.push({cnt+1,i});
            }
            else if(!prime[i]&&!visited[i]&&(now/100)%10!=(i/100)%10&&now%100==i%100&&now/1000==i/1000){ // 세 번째 자리
                visited[i] = true;
                q.push({cnt+1,i});
            }
            else if(!prime[i]&&!visited[i]&&(now/1000)!=(i/1000)&&now%1000==i%1000){ // 네 번째 자리
                visited[i] = true;
                q.push({cnt+1,i});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    separate_prime();
    while(n--){
        int from,to,ans;
        cin >> from >> to;
        ans = bfs(from,to);
        if(ans==-1) cout << "Impossible" << "\n";
        else cout << ans << "\n";
        memset(visited, false, sizeof(visited));
    }
    return 0;
}
