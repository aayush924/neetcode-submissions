class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // Stores indices of elements

        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove indices that are out of the current window bound
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 2. Remove elements smaller than the current element from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. Add current element's index
            dq.push_back(i);

            // 4. Append max to answer once the first window of size k is hit
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};