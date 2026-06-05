class Solution {
    bool isSafe(int &row, int &col, vector<string> &board, int n){
        int i=row-1;
        int j=col-1;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=row-1;
        j=col;
        while(i>=0){
            if(board[i][j]=='Q') return false;
            i--;
        }
        i=row-1;
        j=col+1;
        while(i>=0 && j<n){
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void backtrack(int n, vector<string> &board, vector<vector<string>> &ans, int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(row, col, board, n)){
                board[row][col]='Q';
                backtrack(n, board, ans, row+1);
                board[row][col]='.';
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        backtrack(n, board, ans, 0);
        return ans;
    }
};
