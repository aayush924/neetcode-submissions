class Solution {
    // int recur(vector<int>& nums, int ind, vector<int>& dp){
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int left= recur(nums, ind-1, dp);
    //     int right= nums[ind]+recur(nums, ind-2, dp);
    //     return dp[ind]=max(left, right);
    // }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+2, 0);
        // dp[0]=0;
        // dp[1]=0;
        for(int i=2;i<dp.size();i++){
            dp[i]=max(dp[i-1], nums[i-2]+dp[i-2]);
        }
        return dp[dp.size()-1];
    }
};
