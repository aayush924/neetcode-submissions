class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> bucket(n+1);
        unordered_map<int, int> freq;
        for(int& num: nums){
            freq[num]++;
        }
        for(auto& [key, value]: freq){
            bucket[value].push_back(key);
        }
        vector<int> ans;
        for(int i=n;i>=0;i--){
            for(int& num: bucket[i]){
                ans.push_back(num);
            }
            if(ans.size()==k) break;
        }
        return ans;
    }
};
