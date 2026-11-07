class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump=0;
        for(int i=0;i<nums.size()-1;i++){
            if(maxJump>=nums.size()) return true;
            if(i>maxJump) return false;
            maxJump=max(maxJump, i+nums[i]);
        }
        return maxJump>=nums.size()-1;
    }
};
