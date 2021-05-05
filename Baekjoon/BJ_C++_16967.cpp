#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int h,w,x,y;
    cin >> h >> w >> x >> y;
    vector<vector<int>> v(h+x,vector<int>(w+y,0));
    for(int i=0; i<h+x; i++){
        for(int j=0; j<w+y; j++) cin >> v[i][j];
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            v[i+x][j+y] -= v[i][j];
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cout << v[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
