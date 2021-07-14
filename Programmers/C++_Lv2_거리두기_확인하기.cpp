// The problem link : https://programmers.co.kr/learn/courses/30/lessons/81302
#include <bits/stdc++.h>

using namespace std;

int my[] ={-2,-1,0,1,2}, mx[]={-2,-1,0,1,2},y=0,x=0,ny=0,nx=0,temp=0;

bool distance(vector<string> place){
    queue<pair<int,int>> q;
    for(int i=0; i<place.size(); i++){
        for(int j=0; j<place[i].size(); j++){
            if(place[i][j]=='P') q.push({i,j});
        }
    }
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                ny = y+my[i];
                nx = x+mx[j];
                if(ny==y&&nx==x) continue;
                if(ny<0||ny>=5||nx<0||nx>=5) continue;
                if(abs(my[i])+abs(mx[j])>2)continue;
                if(place[ny][nx]=='P'){
                    if(ny==y){
                        temp = (nx+x)/2;
                        if(place[y][temp]!='X') return false;
                    }
                    else if(nx==x){
                        temp = (ny+y)/2;
                        if(place[temp][x]!='X') return false;
                    }
                    else{
                        if(place[ny][x]!='X'||place[y][nx]!='X') return false;
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place : places){
        answer.push_back(distance(place));
    }
    return answer;
}
