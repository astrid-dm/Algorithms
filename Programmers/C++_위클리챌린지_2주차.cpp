// The problem link : https://programmers.co.kr/learn/courses/30/lessons/83201
#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int n = scores.size();
    for(int i=0; i<n; i++){
        int max_num = 0, min_num = 0, total = 0, cnt = 0, pos = 0;
        for(int j=0; j<n; j++){
            pos = scores[j][i];
            if(scores[i][i]>pos) max_num++;
            if(scores[i][i]<pos) min_num++;
            total += pos;
            cnt++;
        }
        if(max_num==n-1||min_num==n-1) total-=scores[i][i], cnt--;
        total/=cnt;
        if(total>=90) answer+='A';
        else if(total>=80) answer+='B';
        else if(total>=70) answer+='C';
        else if(total>=50) answer+='D';
        else answer+='F';
    }
    return answer;
}
