// The problem link : https://programmers.co.kr/learn/courses/30/lessons/84325#
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string,int> score;
unordered_map<string,int> answer;

void scoreSetting(vector<string> &languages, vector<int> &preference){
    for(int i=0; i<languages.size(); i++) score[languages[i]] = preference[i];
    return;
}

void userScoreSetting(vector<string> &table){
    for(int i=0; i<table.size(); i++){
        int cnt = 6, st = 0, ed = 0;
        string job = "", temp = "";
        while(ed!=table[i].npos){
            ed = table[i].find(' ',st);
            if(ed!=table[i].npos) temp = table[i].substr(st,ed-st);
            else temp = table[i].substr(st);
            if(cnt==6) {
                job = temp;
                answer[job] = 0;
            }
            if(score.find(temp)!=score.end()) answer[job] += cnt*score[temp]; 
            st = ed+1;
            cnt--;
        }
    }
}


string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string ans1 = "";
    int ans2 = 0;
    scoreSetting(languages, preference);
    userScoreSetting(table);
    for(auto a : answer){
        if(ans2<a.second){
            ans1 = a.first;
            ans2 = a.second;
        }
        else if(ans2==a.second){
            if(ans1>a.first){
                ans1 = a.first;
                ans2 = a.second;
            }
        }
    }
    return ans1;
}
