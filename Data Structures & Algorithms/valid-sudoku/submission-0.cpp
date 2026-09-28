class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows;
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> boxes(9);

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                char cell=board[i][j];
                if(cell=='.') continue;
                int box_index=(i/3)*3+j/3;
                if(rows.contains(cell) || columns[j].contains(cell) || boxes[box_index].contains(cell)) return false;
                rows.insert(cell);
                columns[j].insert(cell);
                boxes[box_index].insert(cell);
            }
            rows.clear();
        }
        return true;
    }
};
