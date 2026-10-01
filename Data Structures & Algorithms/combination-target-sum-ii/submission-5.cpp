class Solution {
    void backtrack(const vector<int>& candidates, int target, int start, 
                   vector<int>& comb, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Prune search: since array is sorted, subsequent elements will also exceed target
            if (candidates[i] > target) break;

            // Skip duplicates at the same tree depth
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            comb.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, comb, ans);
            comb.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(candidates, target, 0, comb, ans);
        return ans;
    }
};