class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int max_end=0;
        for(auto& interval:intervals){
            max_end=max(max_end, interval[1]);
        }

        vector<int> max_reach(max_end+1, -1);

        for(auto& interval:intervals){
            int intStart =interval[0];
            max_reach[intStart]=max(max_reach[intStart], interval[1]);
        }
        int currStart=-1;
        int currEnd=-1;
        vector<vector<int>> ans;
        for(int i=0;i<max_reach.size();i++){
            if(i==currEnd){
                currEnd=max(currEnd, max_reach[i]);
                continue;
            }
            if(i>currEnd && currEnd!=-1){
                ans.push_back({currStart, currEnd});
                currStart=i;
                currEnd=max_reach[i];
            }
            else if(i>currStart && max_reach[i]>-1){
                currStart =(i<currEnd)? currStart : i; 
                // currStart=i;
                currEnd=max(currEnd, max_reach[i]);
            }
        }
        ans.push_back({currStart, currEnd});
        return ans;
    }
};
