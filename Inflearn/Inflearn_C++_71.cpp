#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int s = 0, e = 0, m[3] = {-1,1,5};
int ch[10001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int pos = 0, x = 0;
    cin >> s >> e;
    ch[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i=0; i<3; i++){
            pos = x + m[i];
            if(pos==e){
                cout << ch[x] << "\n";
                exit(0);
            }
            if(ch[pos]==0){
                q.push(pos);
                ch[pos] = ch[x] + 1;
            }
        }
    }
    return 0;
}
