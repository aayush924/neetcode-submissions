class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> currInt=intervals[0];
        vector<vector<int>> ans;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>currInt[1]){
                ans.push_back(currInt);
                currInt=intervals[i];
            }
            else{
                currInt[1]=max(currInt[1], intervals[i][1]);
            }
        }
        ans.push_back(currInt);
        return ans;
    }
};
