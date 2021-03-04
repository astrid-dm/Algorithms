#include <iostream>
using namespace std;

bool ch[10] = {false,};

int possible(int c){
    if(c==0){
        if(ch[c]) return 0;
        else return 1;
    }
    int len = 0;
    while(c>0){
        if(ch[c%10]) return 0;
        c/=10;
        len++;
    }
    return len;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n=0, m=0, ans=0, temp=0;
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> temp;
        ch[temp] = true;
    }
    ans = n-100; // 1. +-버튼만 눌러서 움직이는 경우
    if(ans<0) ans = -ans;
    for(int i=0; i<=1000000; i++){ // 2. 숫자와 +-버튼을 같이 누르는 경우
        temp = i;
        int len = possible(temp);
        if(len>0){
            int press = temp-n; // 현재 지점 - 목표 지점 = 눌러야하는 +-버튼 횟수
            if(press<0) press = -press; // 음수일 경우 절대값으로 바꿔준다
            if(ans>len + press) ans = len + press; // len + press = 숫자 버튼 누르는 횟수 + 눌러야하는 +-버튼 횟수
        }
    }
    cout << ans << "\n";
    return 0;
}
