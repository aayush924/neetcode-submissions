class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        int rows=grid.size();
        int columns=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        int time=0;
        while(!q.empty()){
            
            int n=q.size();
            for(int i=0;i<n;i++){
                int r=q.front().first;
                int c=q.front().second;

                if(r+1<rows && grid[r+1][c]==1) {
                    grid[r+1][c]=2;
                    q.push({r+1, c});
                }
                if(r-1>=0 && grid[r-1][c]==1) {
                    grid[r-1][c]=2;
                    q.push({r-1, c});
                }
                if(c+1<columns && grid[r][c+1]==1) {
                    grid[r][c+1]=2;
                    q.push({r, c+1});
                }
                if(c-1>=0 && grid[r][c-1]==1) {
                    grid[r][c-1]=2;
                    q.push({r, c-1});
                }
                q.pop();
                
            }
            if(!q.empty())time++;
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};
