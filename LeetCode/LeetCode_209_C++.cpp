class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size()==1&&nums[0]>=target) return 1;
        int left=0, right=0, sum=nums[0], ans = nums.size()+1;
        while(right<nums.size()){
            if(sum>=target){
                if(ans>right-left+1) ans = right-left+1;
                sum-=nums[left];
                left++;
                if(left>right){
                    right = left;
                    sum = nums[right];
                }
            }
            else{
                right++;
                if(right<nums.size()) sum+=nums[right];
            }
        }
        if(ans==nums.size()+1) return 0;
        else return ans;
    }
};
