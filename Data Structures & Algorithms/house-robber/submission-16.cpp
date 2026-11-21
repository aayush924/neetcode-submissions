class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        int prev2=0;
        for(int i=0;i<n;i++){
            int robbed=nums[i]+prev2;
            prev2=prev;
            int skipped=prev;
            prev=max(robbed, skipped);
        }
        return prev;
    }
};
