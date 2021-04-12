#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.second>b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int,int> map;
    int temp = 0;
    string st = "";
    for(int i=0; i<s.size(); i++){
        if(s[i]==','){
            temp = stoi(st);
            map[temp]++;
            st = "";
        }
        else if(s[i]>='0'&&s[i]<='9') st+=s[i];
        else continue;
    }
    if(st!=""){
            temp = stoi(st);
            map[temp]++;
    }
    vector<pair<int,int>> v(map.begin(),map.end());
    sort(v.begin(),v.end(),comp);
    for(int i=0; i<v.size(); i++) answer.push_back(v[i].first);
    return answer;
}
