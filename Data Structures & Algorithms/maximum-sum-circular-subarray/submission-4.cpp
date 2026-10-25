class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax=0;
        int glMax=nums[0];
        int currMin=0;
        int glMin=nums[0];
        int total=0;
        for(auto& num:nums){
            currMax=max(currMax+num, num);
            currMin=min(currMin+num, num);
            glMax=max(currMax, glMax);
            glMin=min(currMin, glMin);
            total+=num;
        }
        if(glMax<0) return glMax;
        return max(glMax, total-glMin);
    }
};