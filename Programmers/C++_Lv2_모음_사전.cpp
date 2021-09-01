// The problem link : https://programmers.co.kr/learn/courses/30/lessons/84512
#include <string>
#include <vector>

using namespace std;

vector<string> v;
char ch[] = {'A','E','I','O','U'};

void dfs(string temp, int depth){
    if(temp.size()==5) return;
    for(int i=0; i<5; i++){
        temp+=ch[i];
        v.push_back(temp);
        dfs(temp,depth+1);
        temp.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    dfs("",0);
    for(int i=0; i<v.size(); i++){
        if(v[i]==word){
            answer = i+1;
            break;
        }
    }
    return answer;
}
