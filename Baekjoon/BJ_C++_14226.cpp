#include <iostream>
#include <queue>
#define MAX 1002
using namespace std;

int s, arr[MAX][MAX], sc, cl; // screen, clip board

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()){
        sc = q.front().first;
        cl = q.front().second;
        if(sc==s){
            cout << arr[sc][cl] << "\n";
            exit(0);
        }
        q.pop();
        for(int i=0; i<3; i++){
            if(i==1){
                if(sc>1000) break;
                if(arr[sc][sc]==0){
                    arr[sc][sc] = arr[sc][cl]+1;
                    q.push({sc,sc});
                }
            }
            else if(i==2){
                if(sc+cl>1001) break;
                if(arr[sc+cl][cl]==0){
                    arr[sc+cl][cl] = arr[sc][cl]+1;
                    q.push({sc+cl,cl});
                }
            }
            else{
                if(sc<=0) break;
                if(arr[sc-1][cl]==0){
                    arr[sc-1][cl] = arr[sc][cl]+1;
                    q.push({sc-1,cl});
                }
            }
        }
    }
    return 0;
}
