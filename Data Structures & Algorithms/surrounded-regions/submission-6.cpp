class Solution {
    int m;
    int n;

    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited){
        if(i<0 || j<0||i>=m||j>=n||visited[i][j]) return;
        if(board[i][j]!='O') return;
        visited[i][j]=true;
        dfs(board, i+1, j, visited);
        dfs(board, i, j+1, visited);
        dfs(board, i-1, j, visited);
        dfs(board, i, j-1, visited);
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        
        m=board.size();
        n=board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0||i==m-1||j==n-1){
                    dfs(board, i, j, visited);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !visited[i][j]) board[i][j]='X';
            }
        }
        return;
    }
};
