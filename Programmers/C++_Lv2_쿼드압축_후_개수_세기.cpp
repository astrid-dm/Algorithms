// The problem link : https://programmers.co.kr/learn/courses/30/lessons/68936
#include <string>
#include <vector>

using namespace std;

int zero, one, temp;

void quad(vector<vector<int>> &arr, int starty, int endy, int startx, int endx){
    temp = arr[starty][startx];
    bool ch = false;
    for(int i=starty; i<endy; i++){
        for(int j=startx; j<endx; j++){
            if(arr[i][j]!=temp) {ch = true; break;}
        }
    }
    if(ch){
        quad(arr, starty, (starty+endy)/2, startx, (startx+endx)/2); // 1
        quad(arr, starty, (starty+endy)/2, (startx+endx)/2, endx); // 2
        quad(arr, (starty+endy)/2, endy, startx, (startx+endx)/2); // 3
        quad(arr, (starty+endy)/2, endy, (startx+endx)/2, endx); // 4
    }
    else{
        if(temp==0) zero++;
        else one++;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    quad(arr, 0, arr.size(), 0, arr.size());
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}
