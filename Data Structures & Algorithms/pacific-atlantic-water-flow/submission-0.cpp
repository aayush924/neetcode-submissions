class Solution {
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<int>>& ocean, int curr){
        if(r<0 || c<0 || r>=heights.size() || c>=heights[0].size() || 
        ocean[r][c]==1 || heights[r][c]<curr) return;

        ocean[r][c]=1;

        dfs(heights, r+1, c, ocean, heights[r][c]);
        dfs(heights, r-1, c, ocean, heights[r][c]);
        dfs(heights, r, c+1, ocean, heights[r][c]);
        dfs(heights, r, c-1, ocean, heights[r][c]);

        return;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        for(int c=0;c<cols;c++){
            dfs(heights, 0, c, pacific, heights[0][c]);
            dfs(heights, rows-1, c, atlantic, heights[rows-1][c]);
        }
        for(int r=0;r<rows;r++){
            dfs(heights, r, 0, pacific, heights[r][0]);
            dfs(heights, r, cols-1, atlantic, heights[r][cols-1]);
        }
        vector<vector<int>> ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
