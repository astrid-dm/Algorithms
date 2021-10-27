// The problem link : https://programmers.co.kr/learn/courses/30/lessons/87946
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
bool ch[5001];

void check(int left, int cnt, vector<vector<int>> &dungeons){
    for(int i=0; i<dungeons.size(); i++){
        if(!ch[i]&&left>=dungeons[i][0]){
            ch[i] = true;
            check(left-dungeons[i][1],cnt+1,dungeons);
            ch[i] = false;
        }
    }
    answer = max(answer,cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    check(k,0,dungeons);
    return answer;
}
