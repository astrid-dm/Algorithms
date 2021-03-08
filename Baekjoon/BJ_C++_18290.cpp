#include <iostream>
#include <algorithm>
const int MAX = 11;
using namespace std;

int arr[MAX][MAX] = {0,}, ans = -1e4, n = 0, m = 0, k = 0;
bool ch[MAX][MAX] = {false,};
pair<int,int> q[MAX];

bool judge(int y, int x, int cnt){
    for(int i=1; i<=cnt; i++){
        if(q[i].first+1==y&&q[i].second==x) return false;
        if(q[i].first-1==y&&q[i].second==x) return false;
        if(q[i].first==y&&q[i].second+1==x) return false;
        if(q[i].first==y&&q[i].second-1==x) return false;
    }
    return true;
}

void go(int cnt, int sum){
    if(cnt==k){
        if(ans<sum) ans = sum;
        return;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!ch[i][j]&&judge(i,j,cnt)){
                ch[i][j] = true;
                q[cnt+1] = {i,j};
                go(cnt+1,sum+arr[i][j]);
                ch[i][j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    go(0,0);
    cout << ans << "\n";
    return 0;
}
