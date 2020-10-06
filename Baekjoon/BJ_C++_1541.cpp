#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int mini = INT_MAX;
string s = "";
string temp = "";
int minu = 0;
int res = 0;

void calculate(){
    for(int i=0; i<=s.size(); i++){
        if(s[i]=='+'||s[i]=='-'||s[i]=='\0'){ //숫자만 나오고 끝나는 경우도 고려
            if(minu) res -= stoi(temp);
            else res += stoi(temp);
            if(s[i]=='-') minu = 1;
            temp = "";
            continue;
        }
        temp += s[i];
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    calculate();
    cout << res;
    return 0;
}
