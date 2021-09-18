// The problem link : https://programmers.co.kr/learn/courses/30/lessons/42860
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = name.size()-1, temp = name.size()-1, temp2 = 0;
    for(int i=0; i<name.size(); i++){ // 왼쪽오른쪽 중 뭐가 더 빠른지
        temp2 = 0;
        for(int j=i+1; j<name.size(); j++){
            if(name[j]!='A'){
                temp2 = j;
                break;
            }
        }
        answer = min(answer,i+i+1+temp-temp2);
    }
    for(int i=0; i<name.size(); i++){ // 알파벳변경
        temp = 'Z'-name[i]+1;
        answer += min(temp,name[i]-'A');
    }
    return answer;
}
