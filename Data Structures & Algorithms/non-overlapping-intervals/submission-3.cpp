class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end());

        int ans = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= end) {
                // No overlap, advance end
                end = intervals[i][1];
            } else {
                // Overlap: remove the interval with the later end time
                ans++;
                end = min(end, intervals[i][1]);
            }
        }

        return ans;
    }
};