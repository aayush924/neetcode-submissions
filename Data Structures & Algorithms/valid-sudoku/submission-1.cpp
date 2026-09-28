class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int i = 0; i < 9; ++i) {
            bool row[9] = {false}; // Reset automatically for each new row
            
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;

                int val = board[i][j] - '1'; // Map '1'-'9' to 0-8
                int box_index = (i / 3) * 3 + (j / 3);

                if (row[val] || cols[j][val] || boxes[box_index][val]) {
                    return false;
                }

                row[val] = true;
                cols[j][val] = true;
                boxes[box_index][val] = true;
            }
        }
        return true;
    }
};