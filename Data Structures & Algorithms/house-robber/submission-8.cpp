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
        int prev=0;
        int prev2=0;
        int temp=0;
        for(int i=0;i<n;i++){
            temp=max(prev, nums[i]+prev2);
            prev2=prev;
            prev=temp;
        }
        return prev;
    }
};
