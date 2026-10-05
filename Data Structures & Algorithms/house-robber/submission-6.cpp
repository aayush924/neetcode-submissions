class Solution {
    int recur(vector<int>& nums, int ind, vector<int>& dp){
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int left= recur(nums, ind-1, dp);
        int right= nums[ind]+recur(nums, ind-2, dp);
        return dp[ind]=max(left, right);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);
        return recur(nums, n-1, dp);
    }
};
