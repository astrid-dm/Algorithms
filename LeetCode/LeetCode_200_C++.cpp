// The problem link : https://leetcode.com/problems/number-of-islands/
// The result : 12.4MB, 32ms
class Solution {
public:
    int my[4]={0,1,0,-1}, mx[4]={1,0,-1,0}, nx, ny, yy, xx, ans=0;
    bool ch[301][301];
    void go(int y, int x, vector<vector<char>>& grid){
        for(int i=0; i<4; i++){
            ny = y+my[i];
            nx = x+mx[i];
            if(ny<0||ny>=yy||nx<0||nx>=xx) continue;
            if(grid[ny][nx]=='1'&&!ch[ny][nx]){
                ch[ny][nx] = true;
                go(ny,nx,grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        yy = grid.size(); xx = grid[0].size();
        for(int i=0; i<yy; i++){
            for(int j=0; j<xx; j++){
                if(grid[i][j]=='1'&&!ch[i][j]){
                    ans++;
                    ch[i][j] = true;
                    go(i,j,grid);
                }
            }
        }
        return ans; 
    }
};
