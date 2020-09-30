#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n = 0, m = 0, pos = 0, temp = 0;
int mv[3] = {-1,1,0};
int arr[100001];
int ch[100001] = {0,};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    if(n==m) {
        cout << 0 << "\n";
        exit(0);
    }
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i=0; i<3; i++){
            if(i==2){
                pos = temp*2;
            }
            else pos = temp+mv[i];
            if(pos>100000);
            else if(pos==m){
                cout << ch[temp] + 1 << "\n";
                exit(0);
            }
            else if(ch[pos]==0){
                ch[pos] = ch[temp]+1;
                q.push(pos);
            }
        }
    }

    return 0;
}
