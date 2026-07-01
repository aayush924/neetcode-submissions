class Solution {
    int ans=0;
    int t=0;
    void backtrack(vector<int>& nums, int ind, int sum){
        if(ind==nums.size()){
            if(sum==t) ans++;
            return;
        }
        backtrack(nums, ind+1, sum+nums[ind]);
        backtrack(nums, ind+1, sum-nums[ind]);
        return;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        t=target;
        backtrack(nums, 0, 0);
        return ans;
    }
};
