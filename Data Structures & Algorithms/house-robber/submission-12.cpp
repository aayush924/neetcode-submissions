class Solution {
    int dp(vector<int>& nums, int i, vector<int>& memo){
        if(i>=nums.size()){
            return 0;
        }
        if(memo[i]!=-1) return memo[i];
        int robbed=nums[i]+dp(nums, i+2, memo);
        int skipped=dp(nums, i+1, memo);

        return memo[i]=max(robbed, skipped);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return dp(nums, 0, memo);
    }
};
