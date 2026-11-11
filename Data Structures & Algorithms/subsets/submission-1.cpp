class Solution {
    void recur(vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset, int i){
        if(i==nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        
        recur(nums, ans, subset, i+1);
        subset.pop_back();
        recur(nums, ans, subset, i+1);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        recur(nums, ans, subset, 0);
        return ans;
    }
};
