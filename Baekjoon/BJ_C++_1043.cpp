#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,t,p,pn,ans=0;
    bool ch[51]; // 진실을 아는지 여부
    bool res[51]; // 과장된 이야기를 할 수 있는 파티 여부
    cin >> n >> m;
    vector<int> party[m+1];
    queue<int> q;
    memset(ch,false,sizeof(ch)); // 배열 초기화
    memset(res,false,sizeof(res)); // 배열 초기화
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> pn;
        ch[pn] = true; // 진실을 아는 사람 체크
        q.push(pn); // 큐에 진실을 아는 사람 삽입
    }
    for(int i=1; i<=m; i++){
        cin >> pn; // 파티에 참석하는 사람 수
        for(int j=0; j<pn; j++){
            cin >> p; // 해당 파티에 참석하는 사람
            party[i].push_back(p); // 해당 파티에 참석하는 사람 번호 삽입
        }
    }
    while(!q.empty()){
        p = q.front();
        q.pop();
        for(int i=1; i<=m; i++){
            if(find(party[i].begin(),party[i].end(),p)!=party[i].end()){
                res[i] = true;
                if(party[i].size()>1){
                    for(int j=0; j<party[i].size(); j++){
                        if(!ch[party[i][j]]){
                            ch[party[i][j]] = true;
                            q.push(party[i][j]);
                        }
                    }
                }
            }
        }
    }
    for(int i=1; i<=m; i++) if(!res[i]) ans++; 
    cout << ans << "\n";
    return 0;
}
