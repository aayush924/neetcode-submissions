class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        unordered_map<int, int> freq;

        for (int i:nums){
            freq[i]++;
        }

        for (auto& it: freq){
            minH.push({it.second, it.first});
            if(minH.size()>k){
                minH.pop();
            }
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};
