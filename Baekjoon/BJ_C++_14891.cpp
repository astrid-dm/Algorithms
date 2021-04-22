#include <iostream>
#include <vector>
using namespace std;

int arr[5][9], idx[5][3], m[5] = {0,0,0,0,0}, r, a, b, ans = 0;
char c;

void go2(int x, int y){
    if(y==1) y=-1;
    else y = 1;
    for(int i=0; i<3; i++){
        idx[x][i] += y;
        if(idx[x][i]<1) idx[x][i] = 8;
        else if(idx[x][i]>8) idx[x][i] = 1;
    }
}

void go(vector<pair<int,int>> &v, int n){
    int pos = v[n].first, dir = v[n].second;
    m[pos] = dir;
    for(int i=pos-1; i>0; i--){
        if(m[i+1]==0) continue;
        if(arr[i+1][idx[i+1][2]]!=arr[i][idx[i][1]]){
            if(abs(pos-i)%2==1){ 
                if(dir==1) m[i] = -1;
                else m[i] = 1;
            }
            else m[i] = dir;
        }
        else m[i] = 0;
    }
    for(int j=pos+1; j<=4; j++){
        if(m[j-1]==0) continue;
        if(arr[j-1][idx[j-1][1]]!=arr[j][idx[j][2]]){
            if(abs(j-pos)%2==1){
                if(dir==1) m[j] = -1;
                else m[j] = 1;
            }
            else m[j] = dir;
        }
        else m[j] = 0;
    }
    for(int i=1; i<=4; i++) if(m[i]!=0) go2(i,m[i]);
    for(int i=1; i<=4; i++) m[i] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=1; i<=4; i++){
        for(int j=1; j<=8; j++){
            cin >> c;
            arr[i][j] = c-'0';
        }
    }
    for(int i=1; i<=4; i++){
        idx[i][0] = 1;
        idx[i][1] = 3; 
        idx[i][2] = 7;
    }
    cin >> r;
    vector<pair<int,int>> v(r);
    for(int i=0; i<r; i++){
        cin >> a >> b;
        v[i] = {a,b};
    }
    for(int i=0; i<r; i++)go(v,i);
    int score = 1;
    for(int i=1; i<=4; i++){
        if(arr[i][idx[i][0]]==1) ans+=score;
        score*=2;
    }
    cout << ans << "\n";
    return 0;
}
