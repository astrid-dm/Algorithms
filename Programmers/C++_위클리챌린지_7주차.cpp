// The problem link : https://programmers.co.kr/learn/courses/30/lessons/86048
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer(enter.size(),0);
    unordered_map<int,int> mp;
    int left=0,right=0,in=0,out=0;
    while(right<leave.size()){
        in = enter[left];
        out = leave[right];
        if(mp.find(out)==mp.end()){
            mp[in]++;
            left++;
        }else{
            answer[out-1] += mp.size()-1;
            mp.erase(out);
            for(auto i : mp) answer[i.first-1]++;
            right++;
        }
    }
    return answer;
}
