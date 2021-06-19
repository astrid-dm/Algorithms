// The problem link : https://programmers.co.kr/learn/courses/30/lessons/17679
#include <string>
#include <vector>

using namespace std;

int h,w,ny,nx,my[]={0,1,1},mx[]={1,0,1};

int friends(vector<string> &board){
    int score = 0;
    vector<vector<bool>> ch(h,vector<bool>(w,false));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(board[i][j]!=' '){
                int temp = 1;
                for(int a=0; a<3; a++){
                    ny = i+my[a];
                    nx = j+mx[a];
                    if(ny<0||ny>=h||nx<0||nx>=w) break;
                    if(board[ny][nx]==board[i][j]){
                        temp++;
                    }
                }
                if(temp==4){
                    if(ch[i][j]) temp--;
                    else ch[i][j] = true;
                    for(int a=0; a<3; a++){
                        ny = i+my[a];
                        nx = j+mx[a];
                        if(ny<0||ny>=h||nx<0||nx>=w) break;
                        if(ch[ny][nx]) temp--;
                        else ch[ny][nx] = true;
                    }
                    score+=temp;
                }
            }
        }
    }  // 터트린 블록들은 공란으로 표시함
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(ch[i][j]) board[i][j] = ' ';
        }
    }
    // 터트릴 블록들은 true로 표시함
    for(int i=h-1; i>=0; i--){
        for(int j=0; j<w; j++){
            if(board[i][j]==' '){
                for(int a=i-1; a>=0; a--){
                    if(a<0) break;
                    if(board[a][j]!=' '){
                        board[i][j] = board[a][j];
                        board[a][j] = ' ';
                        break;
                    }
                }
            }
        }
    }
    return score;
}

int solution(int m, int n, vector<string> board) {
    h = m, w = n;
    int answer = 0, temp = 0;
    while(true){
        temp = friends(board);
        answer += temp;
        if(temp==0) break;
    }
    return answer;
}
