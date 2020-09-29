#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[302][302] = {0,}, v[302][302] = {0,}, year = 0, total = 0, temp = 0, n = 0, m = 0;
bool ch[302][302] = {false,};
int my[4] = {1,0,-1,0};
int mx[4] = {0,1,0,-1};

int melt(int y, int x){
    int cnt = 0;
    for(int i=0; i<4; i++){
        int ny = y + my[i];
        int nx = x + mx[i];
        if(arr[ny][nx]==0) cnt++;
    }
    return cnt;
}

void track(int y, int x){
    for(int i=0; i<4; i++){
        int ny = y + my[i];
        int nx = x + mx[i];
        if(ny>=1&&ny<=n&&nx>=1&&nx<=m){
            if(v[ny][nx]!=0&&!ch[ny][nx]){
                ch[ny][nx] = true;
                track(ny,nx);
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m; // n = y, m = x;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    while(true){
        temp = 0;
        ++year;
        for(int i=2; i<=n-1; i++){
            for(int j=2; j<=m-1; j++){
                if(arr[i][j]>0){
                    v[i][j] = arr[i][j] - melt(i,j);
                    if(v[i][j]<0) v[i][j] = 0;
                }
                temp+=v[i][j];
            }
        }
        for(int i=2; i<=n-1; i++){
            for(int j=2; j<=m-1; j++){
                arr[i][j] = v[i][j];
                if(v[i][j]!=0&&!ch[i][j]){
                    total++;
                    ch[i][j] = true;
                    track(i,j);
                }
            }
        }
        if(total>1){
            cout << year << "\n";
            exit(0);
        }
        if(temp==0){
            cout << temp << "\n";
            exit(0);
        }
        memset(ch,false,sizeof(ch));
        total = 0;
    }
    return 0;
}
