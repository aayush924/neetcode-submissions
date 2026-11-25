class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<pair<int, int>> dirs={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}});
        efforts[0][0]=0;
        while(!pq.empty()){
            int k=pq.size();
            for(int i=0;i<k;i++){
                pair<int, int> src=pq.top().second;
                int x=src.first;
                int y=src.second;
                int currefforts=pq.top().first;
                pq.pop();
                if(currefforts>efforts[x][y]) continue;

                for(auto& [x1, y1]:dirs){
                    if(x+x1>=0 && x+x1<m && y+y1>=0 && y+y1<n){
                        int effort=abs(heights[x+x1][y+y1]-heights[x][y]);
                        if(effort>efforts[x][y]){
                            if(effort<efforts[x+x1][y+y1]){
                                efforts[x+x1][y+y1]=effort;
                                pq.push({effort, {x+x1, y+y1}});
                            }
                        }
                        else{
                            if(efforts[x][y]<efforts[x+x1][y+y1]){
                                efforts[x+x1][y+y1]=efforts[x][y];
                                pq.push({efforts[x][y], {x+x1, y+y1}});
                            }
                        }
                    }
                }
            }
        }
        return efforts[m-1][n-1];
    }
};