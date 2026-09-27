class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minH;
        vector<vector<int>> bucket(nums.size()+1);
        unordered_map<int, int> freq;

        for (int i:nums){
            freq[i]++;
        }

        for (auto& it: freq){
            // minH.push({it.second, it.first});
            // if(minH.size()>k){
            //     minH.pop();
            // }

            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=bucket.size()-1;i>=0;i--){
            for (int j:bucket[i]){
                if(ans.size()==k) return ans;
                ans.push_back(j);
            }
        }
        return ans;
    }
};
