// The problem link : https://programmers.co.kr/learn/courses/30/lessons/86491
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0, width = 0, height = 0, arr[10001][2];
    for(int i=0; i<sizes.size(); i++){
        arr[i][0] = max(sizes[i][0],sizes[i][1]);
        arr[i][1] = min(sizes[i][0],sizes[i][1]);
        width = max(width,arr[i][0]);
        height = max(height,arr[i][1]);
    }
    answer = width*height;
    return answer;
}
