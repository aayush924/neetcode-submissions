class Solution {
    int dp(vector<int>& nums, int i, vector<int>& memo){
        if(i<0) return 0;
        if(memo[i]!=-1) return memo[i];

        int robbed=nums[i]+dp(nums, i-2, memo);
        int skipped=dp(nums, i-1, memo);

        return memo[i]=max(robbed, skipped);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> memo(n, -1);
        return dp(nums, n-1, memo);
    }
};
