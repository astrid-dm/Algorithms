#include <iostream>
const int MAX = 11;
using namespace std;

int arr[MAX][MAX] = {0,}, ans = 1e4, cnt = 0, paper[6]={0,5,5,5,5,5};
void go (int y, int x){
   if(x==MAX){
       go(y+1,1); // 다음줄 진행
   }
   if(y==MAX){
       ans = min(ans,cnt); // 마지막 줄 까지 끝냈으면 최소값으로 답을 정하기
       return;
   }
   if(arr[y][x]==0) go(y,x+1);
   for(int i=5; i>=1; i--){
       if(paper[i]==0||y+i>MAX||x+i>MAX) continue; // 종이를 다 썻거나 종이를 덮었을때 범위를 넘어가면 다음 종이로 패스하기
       bool ch = false;
       for(int j=0; j<i; j++){
           for(int k=0; k<i; k++){
               if(arr[y+j][x+k]==0){
                   ch = true;
                   break;
               }
           }
           if(ch) break;
       }
       if(ch) continue; // 덮을수 없다는 뜻이니 다음 종이로 패스
       for(int j=0; j<i; j++){ // 덮었다고 가정하기
           for(int k=0; k<i; k++){
               arr[y+j][x+k] = 0;
           }
       }
       paper[i]--;
       cnt++;
       go(y,x+i); // 덮은 영역만큼 건너뛰고 다음 영역으로 넘어가기
       for(int j=0; j<i; j++){
           for(int k=0; k<i; k++){
               arr[y+j][x+k] = 1; // 덮었던 종이 치우기
           }
       }
       paper[i]++;
       cnt--;
   }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=1; i<MAX; i++){
        for(int j=1; j<MAX; j++){
            cin >> arr[i][j];
        }
    } 
    go(1,1);
    if(ans==1e4) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}
