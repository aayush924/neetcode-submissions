class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, down = m - 1;
        int left = 0, right = n - 1;
        vector<int> ans;

        while (up <= down && left <= right) {
            // Traverse from Left to Right along the 'up' row
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[up][j]);
            }
            up++;

            // Traverse from Up to Down along the 'right' column
            for (int i = up; i <= down; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Make sure row boundary is still valid before moving Left
            if (up <= down) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[down][j]);
                }
                down--;
            }

            // Make sure column boundary is still valid before moving Up
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};