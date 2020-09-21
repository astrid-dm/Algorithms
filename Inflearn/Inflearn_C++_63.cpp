#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n = 0, m = 0, arr[21][21];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y=0,x=0,c=0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> y >> x >> c;
        arr[y][x] = c;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
