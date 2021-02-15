#include <string>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i=0; i<new_id.size(); i++){
        if(answer.size()>=15) break;
        if(new_id[i]>='A'&&new_id[i]<='Z') answer += new_id[i]+32;
        else if((new_id[i]>='a'&&new_id[i]<='z')||new_id[i]=='-'||new_id[i]=='_'||(new_id[i]>='0'&&new_id[i]<='9')&&new_id[i]!='.') answer += new_id[i];
        else if(new_id[i]=='.'){
            if(answer.size()==0) continue;
            else if(answer[answer.size()-1]=='.') continue;
            else if(answer.size()==14) break;
            else answer+=new_id[i];
        }
    }
    if(answer[answer.size()-1]=='.') answer.erase(answer.size()-1,1);
    if(answer.size()==0) answer = "aaa";
    if(answer.size()<3){
        if(answer[answer.size()-1]=='.') answer[answer.size()-1] = answer[answer.size()-2];
        while(answer.size()!=3){
            answer+=answer[answer.size()-1];
        }
    }
    return answer;
}
