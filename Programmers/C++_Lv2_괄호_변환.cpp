#include <string>
#include <vector>

using namespace std;
string answer = "", samp = "";

void check(string s){
    if(s=="") return;
    int temp = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') temp++;
        else temp--;
        if(temp==0){ // 균형잡힌 문자열 u가 나옴
            if(s[0]=='('){ // 동시에 올바른 문자열임
                for(int j=0; j<=i; j++) answer += s[j]; // u를 그대로 갖다 붙임
                samp = "";
                for(int j=i+1; j<s.size(); j++) samp += s[j];
                check(samp); // 나머지 문자 v에 대해 재귀 진행
            }
            else{ //올바른 문자열은 아님
                answer += '('; // 첫째 자리는 무조건 '('
                samp = "";
                for(int j=i+1; j<s.size(); j++) samp += s[j];
                check(samp); // 나머지 문자 v에 대해 재귀 진행
                answer += ')'; // 마지막 자리는 무조건 ')'
                for(int j=1; j<=i-1; j++){ // u의 처음과 마지막을 제외하고 뒤집어서 붙임
                    if(s[j]=='(') answer += ')';
                    else answer += '(';
                }
            }
            return;
        }
    }
}

string solution(string p) {
    check(p);
    return answer;
}
