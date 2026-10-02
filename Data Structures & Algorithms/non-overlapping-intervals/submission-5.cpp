class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int count=0;
        int prev=intervals[0][1];
        int i=1;
        while(i<intervals.size()){
            if(intervals[i][0]<prev){
                count++;
            }
            else{
                prev=intervals[i][1];
            }
            i++;
        }
        return count;
    }
};
