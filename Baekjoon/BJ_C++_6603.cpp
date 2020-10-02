#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n = 0;
int arr[14];
bool ch[50] = {false,};

void bt(int y, int num){
    if(y>n){
        if(num==6){
            for(int i=1; i<=50; i++){ //전체 입려 가능한 숫자의 범위는 1~50
                if(ch[i]) cout << i << " "; 
            }
            cout << "\n";
        }
        else return;
    }
    else{
        ch[arr[y]] = true; // ch[arr[y]] 주의
        bt(y+1,num+1);
        ch[arr[y]] = false; // ch[arr[y]] 주의
        bt(y+1,num);
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cin >> n;
        if(n==0) break;
        for(int i=1; i<=n; i++) cin >> arr[i];
        bt(1,0); // 본인은 갯수를 0개부터 시작했슴
        memset(ch,false,sizeof(ch));
        cout << "\n";
    }
    return 0;
}
