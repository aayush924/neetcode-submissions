class Solution {
    bool recur(vector<int>& nums, int ind, vector<int>& memo){
        if(ind==nums.size()-1) return true;
        if(memo[ind]!=-1) return memo[ind];
        int jumps=nums[ind];
        if (jumps==0) return false;
        for(int i=ind+1;i<ind+jumps+1;i++){
            if(recur(nums, i, memo)) return memo[i]=1;
        }
        return memo[ind]=0;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size()+1, -1);

        return recur(nums, 0, memo);
    }
};
