#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100000
using namespace std;
int n = 0, m = 0, ans = 0;
int v[501][501]; //학생들의 정보
int d[501][501]; //플로이드와샬 결과

void floydwarshall(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[i][j] = v[i][j]; //값을 복사해준다
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][j]>d[i][k]+d[k][j]&&d[i][j]==INF) d[i][j] = 1;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 0, b = 0;
    cin >> n >> m;
    fill(&v[0][0],&v[n][n],INF); // 모든 지점은 갈 수 없다고 설정
    for(int i=1; i<=n; i++){
        v[i][i] = 0; // 자기자신은 0으로 초기화
    }
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a][b] = 1; // a에서 b로 갈 수 있다고 설정
    }

    floydwarshall();

    for(int i=1; i<=n; i++){
        int start = 0, stop = 0;
        for(int j=1; j<=n; j++){
            if(d[i][j]==1) start++;
            if(d[j][i]==1) stop ++;
        }
        if(start+stop == n-1) ans ++;
    }
    cout << ans << "\n";
    return 0;
}
