class Solution {
    int dfs(vector<int>& nums, int i, int prev, vector<vector<int>>& memo){
        if(i>=nums.size()) return 0;
        if(memo[i][prev+1]!=-1) return memo[i][prev+1];
        int take=0;
        if(prev==-1 || nums[i]>nums[prev]){
            take=1+dfs(nums, i+1, i, memo);
        }
        int notTake=dfs(nums, i+1, prev, memo);

        return memo[i][prev+1]=max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> memo(n, vector<int>(n+1, -1));
        return dfs(nums, 0, -1, memo);
    }
};
