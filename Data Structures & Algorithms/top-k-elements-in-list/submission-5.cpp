class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype([](const pair<int, int>& a, const pair<int, int>& b){
            return a.second>b.second;
        })> minHeap;

        unordered_map<int , int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        for(auto& [key, value]: freq){
            minHeap.push({key, value});
            if(minHeap.size()>k) {
                minHeap.pop();
            }
        }
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }
        return ans;
    }
};
