#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n = 0, m = 0, ans = 0, temp = 0;
int arr[21][21];
bool check[21] = {false,};

void dfs(int x){
    if(x==n){
        ans++;
        return;
    }
    else{
        for(int i=1; i<=n; i++){
            if(arr[x][i]==1&&check[i]==false){
                check[i] = true;
                dfs(i);
                check[i] = false;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 0, b = 0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        arr[a][b]=1;
    }
    check[1] = true;
    dfs(1);
    cout << ans << "\n";

    return 0;
}
