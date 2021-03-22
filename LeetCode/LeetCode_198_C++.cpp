class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = nums[0], sum[101];
        sum[0] = nums[0];
        if(nums.size()>1) {
            sum[1] = max(nums[0],nums[1]);
            ans = max(sum[0],sum[1]);
        }
        for(int i=2; i<nums.size(); i++){
            sum[i] = max(sum[i-2]+nums[i],sum[i-1]);
            if(ans<sum[i]) ans = sum[i];
        }
        return ans;
    }
};
