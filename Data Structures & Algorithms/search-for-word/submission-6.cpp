class Solution {
    bool recur(vector<vector<char>>& board, string& word, int i, int j, int ind, unordered_set<int>& visited){
        if(ind>=word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return false;
        }
        int val=i*board[0].size() + j;
        if(board[i][j]!=word[ind] || visited.contains(val)){
            return false;
        }
        visited.insert(val);
        bool found= (
            recur(board, word, i, j+1, ind+1, visited) ||
            recur(board, word, i+1, j, ind+1, visited) ||
            recur(board, word, i, j-1, ind+1, visited) ||
            recur(board, word, i-1, j, ind+1, visited)
        );
        visited.erase(val);
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_set<int> visited;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(recur(board, word, i, j, 0, visited)){
                    return true;
                }
                visited.clear();
            }
        }
        return false;
    }
};
