#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string,int> gemlist; 
    int st = 0, end = 0;
    for(auto gem : gems) gemlist[gem] = 0;
    int total = gemlist.size(), cnt = 0, temp_st=0, temp_end=0, maxi = 1e9;
    while(true){
        if(cnt==total){
            if(end-st<maxi){
                temp_st = st;
                temp_end = end;
                maxi = end-st;
            }
            if(gemlist[gems[st]]>1){
                gemlist[gems[st]]--;
                st++;
            }
            else{
                gemlist[gems[st]]--;
                st++;
                cnt--;
            }
        }
        else if(end==gems.size()) break;
        else{
            gemlist[gems[end]]++;
            end++;
        }
    }
    answer.push_back(temp_st+1); answer.push_back(temp_end);
    return answer;
}
