#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void check(int n){
    vector<int> v[n+2][n+2];
    int a = 0, res = 0
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a;
            v[i][j].push_back(a);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(v[i][j]>v[i-1][j]&&v[i][j]>v[i+1][j]){ //Up Down
                if(v[i][j]>v[i][j-1]&&v[i][j]>v[i][j+1]){ // Left Right
                    res++;
                }
            }
        }
    }
    cout << res << "\n";
    return;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    cin >> N;
    
    check(N);

    return 0;
}
