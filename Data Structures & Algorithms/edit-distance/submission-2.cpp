class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 1. Base case: j == n (word2 exhausted, delete remaining chars of word1)
        for (int i = 0; i <= m; i++) {
            dp[i][n] = m - i;
        }
        // 2. Base case: i == m (word1 exhausted, insert remaining chars of word2)
        for (int j = 0; j <= n; j++) {
            dp[m][j] = n - j;
        }

        // 3. Fill the table backward from bottom-right to top-left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int removeOp  = 1 + dp[i + 1][j];
                    int insertOp  = 1 + dp[i][j + 1];
                    int replaceOp = 1 + dp[i + 1][j + 1];
                    dp[i][j] = min({removeOp, insertOp, replaceOp});
                }
            }
        }

        // Matches the initial top-down call: dp(word1, word2, 0, 0)
        return dp[0][0];
    }
};