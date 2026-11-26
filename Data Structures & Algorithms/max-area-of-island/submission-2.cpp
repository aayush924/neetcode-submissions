class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j]==0) return 0;
        visited[i][j]=true;

        return 1+dfs(grid, i+1, j, visited) +dfs(grid, i, j+1, visited) +
        dfs(grid, i-1, j, visited) + dfs(grid, i, j-1, visited);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    maxi=max(maxi, dfs(grid, i, j, visited));
                }
            }
        }
        return maxi;
    }
};
