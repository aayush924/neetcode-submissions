class Solution {
    void rot(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& q, int& fresh){
        if(x>=grid.size() || x<0 || y<0 || y>=grid[0].size() || grid[x][y]==0 || grid[x][y]==2){
            return;
        }
        grid[x][y]=2;
        q.push({x, y});
        fresh--;
        return;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int time=0;
        while(!q.empty() && fresh>0){
            int n=q.size();
            time++;
            for(int a=0;a<n;a++){
                pair<int, int> cell=q.front();
                int x=cell.first;
                int y=cell.second;
                q.pop();
                rot(grid, x+1, y, q, fresh);
                rot(grid, x-1, y, q, fresh);
                rot(grid, x, y+1, q, fresh);
                rot(grid, x, y-1, q, fresh);
            }
        }
        return (fresh==0)? time: -1;
    }
};
