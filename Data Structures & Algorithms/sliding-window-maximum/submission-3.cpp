class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

        pq.push({nums[0], 0});
        for(int i=1;i<k;i++){
            if(nums[i]>=pq.top().first){
                while(!pq.empty()){
                    pq.pop();
                }
            }
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);
        for(int i=k;i<nums.size();i++){
            while(!pq.empty() && pq.top().second<=i-k) pq.pop();
            if(!pq.empty() && nums[i]>=pq.top().first){
                while(!pq.empty()){
                    pq.pop();
                }
            }
            pq.push({nums[i], i});
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
