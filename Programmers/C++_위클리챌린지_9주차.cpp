#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int a,b,score=0;
vector<int> v[101];
bool ch[101];

void getCheck(int pos, bool operationMark){
    for(int i=0; i<v[pos].size(); i++){
        if(!ch[v[pos][i]]){
            ch[v[pos][i]] = true;
            if(operationMark) score++;
            else score--;
            getCheck(v[pos][i], operationMark);
        }
    }
}

void getSorted(vector<vector<int>> &wires){
    for(int i=0; i<wires.size(); i++){
        a = wires[i][0];
        b = wires[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    getSorted(wires);
    for(int i=0; i<wires.size(); i++){
        a = wires[i][0];
        b = wires[i][1];
        ch[a] = true;
        ch[b] = true;
        getCheck(a,true);
        getCheck(b,false);
        answer = min(answer,abs(score));
        score = 0;
        memset(ch,false,sizeof(ch));
    }
    return answer;
}
