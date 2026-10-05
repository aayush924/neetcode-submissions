class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j, unordered_set<int>& visited, int& area){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        int val=i*grid[0].size()+j;
        if(visited.contains(val)) return;
        visited.insert(val);
        area++;
        dfs(grid, i+1, j, visited, area);
        dfs(grid, i-1, j, visited, area);
        dfs(grid, i, j+1, visited, area);
        dfs(grid, i, j-1, visited, area);
        return;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int area=0;
        unordered_set<int> visited;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !visited.contains(i*grid[0].size()+j)){
                    dfs(grid, i, j, visited, area);
                    ans=max(ans, area);
                    area=0;
                }
            }
        }
        return ans;
    }
};
