class Solution {
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return;
        }
        if(visited[i][j]==1 || board[i][j]=='X') return;
        visited[i][j]=1;
        dfs(board, visited, i+1, j);
        dfs(board, visited, i-1, j);
        dfs(board, visited, i, j+1);
        dfs(board, visited, i, j-1);
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();//rows
        int n=board[0].size();//cols
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            dfs(board, visited, i, 0);
            dfs(board, visited, i, n-1);
        }
        for(int j=0;j<n;j++){
            dfs(board, visited, 0, j);
            dfs(board, visited, m-1, j);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};
