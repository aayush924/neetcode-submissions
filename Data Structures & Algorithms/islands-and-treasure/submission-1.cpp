class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // vector<int> visited;
        queue<vector<int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    q.push({i, j});
                }
            }
        }
        //BFS
        int count=0;

        while(!q.empty()){
            count++;
            int n=q.size();
            for(int i=0;i<n;i++){//level
                int x=q.front()[0];
                int y=q.front()[1];
                if(x>0){
                    if(grid[x-1][y]==INT_MAX){
                        grid[x-1][y]=count;
                        q.push({x-1,y});
                    }
                }
                if(y>0){
                    if(grid[x][y-1]==INT_MAX){
                        grid[x][y-1]=count;
                        q.push({x,y-1});
                    }
                }
                if(x<grid.size()-1){
                    if(grid[x+1][y]==INT_MAX){
                        grid[x+1][y]=count;
                        q.push({x+1,y});
                    }
                }
                if(y<grid[0].size()-1){
                    if(grid[x][y+1]==INT_MAX){
                        grid[x][y+1]=count;
                        q.push({x,y+1});
                    }
                }
                q.pop();
                
            }
        }
        return;
    }
};
