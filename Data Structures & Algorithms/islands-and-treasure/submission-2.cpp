class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        unordered_set<int> visited;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if (grid[i][j]==0){
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dirs={{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto& [dx, dy]: dirs){
                    int x1=dx+x;
                    int y1=dy+y;
                    if(x1<0 || y1<0 || x1>=grid.size() || y1>=grid[0].size() || 
                    grid[x1][y1]!=INT_MAX) continue;
                    grid[x1][y1]=grid[x][y]+1;
                    q.push({x1, y1});
                }
            }
        }
        return;
    }
};
