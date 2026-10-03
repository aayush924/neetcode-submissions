class Solution {
    void recur(set<vector<int>>& ans, vector<int>& subset, vector<int>& nums, int ind){
        ans.insert(subset);
        if(ind>=nums.size()){
            
            return;
        }
        // ans.insert(subset);
        subset.push_back(nums[ind]);
        recur(ans, subset, nums, ind+1);
        subset.pop_back();
        recur(ans, subset, nums, ind+1);
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> subset;
        recur(ans, subset, nums, 0);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
