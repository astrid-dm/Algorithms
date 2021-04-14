#include <iostream>
#include <queue>
#include <stack>
#define MAX 100001
using namespace std;

int n,k,pos,temp,m[]={-1,1,0},path[MAX],arr[MAX];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    if(n==k){
        cout << 0 << "\n" << n << "\n";
        exit(0);
    }
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        pos = q.front();
        q.pop();
        if(pos==k){ // 정답
            cout << arr[pos]<< "\n";
            stack<int> ans;
            ans.push(pos);
            for(int i=pos; i!=n; i=path[i]) ans.push(path[i]);
            while(!ans.empty()){
                cout << ans.top() << " ";
                ans.pop();
            }
            cout << "\n";
            exit(0);
        }
        for(int i=0; i<3; i++){
            if(i==2) temp=pos*2;
            else temp=pos+m[i];
            if(temp<0||temp>=MAX) continue; // 이러면 더이상 탐색 필요 X
            else if(arr[temp]==0){
                arr[temp] = arr[pos]+1;
                path[temp] = pos;
                q.push(temp);
            }
        }
    }
    return 0;
}
