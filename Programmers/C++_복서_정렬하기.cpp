// The problem link : https://programmers.co.kr/learn/courses/30/lessons/85002
// 프로그래머스 위클리 챌린지 6주차
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct boxer{
    int num;
    float res;
    int big;
    int weight;
};

bool win(boxer &a, boxer &b){
    if(a.res==b.res){
        if(a.big==b.big){
            if(a.weight==b.weight) return a.num<b.num;
            else return a.weight>b.weight;
        }
        else return a.big>b.big;
    }
    else return a.res>b.res;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<boxer> score; // {번호, 승률, 자기보다 큰 상대 이긴 횟수, 본인 체중}
    for(int i=0; i<head2head.size(); i++){
        float win = 0, plays = weights.size();
        int big = 0;
        for(int j=0; j<head2head[i].size(); j++){
            if(head2head[i][j]=='N') plays-=1.0;
            else if(head2head[i][j]=='W'){
                win+=1.0;
                if(weights[i]<weights[j]) big++;
            }
        }
        if(plays>0) score.push_back({i,win/plays,big,weights[i]});
        else score.push_back({i,0,0,weights[i]});
    }
    sort(score.begin(),score.end(),win);
    for(auto a : score) answer.push_back(a.num+1);
    return answer;
}
