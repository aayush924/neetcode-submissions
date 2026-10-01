class Solution {
    void recur(vector<int>& nums, int& target, int ind, int sum,  vector<vector<int>>& ans,
    vector<int>& comb){
        if(sum>target || ind>=nums.size()) {
           return; 
        }
        if(sum==target) {
            ans.push_back(comb);
            return;
        }
        comb.push_back(nums[ind]);
        recur(nums,target, ind, sum+nums[ind], ans, comb);
        comb.pop_back();
        recur(nums, target, ind+1, sum, ans, comb);

        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        recur(nums, target, 0, 0, ans, comb);
        return ans;
    }
};
