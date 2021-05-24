// The problem link : https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int> sum(amount+1,1e9);
        sum[0] = 0;
        for(int i=0; i<coins.size(); i++){
            for(int j=coins[i]; j<=amount; j++){
                sum[j] = min(sum[j],1+sum[j-coins[i]]);
            }
        }
        if(sum[amount]!=1e9) return sum[amount];
        else return -1;
    }
};
