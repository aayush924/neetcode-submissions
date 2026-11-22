class Solution {
    int dp(string& word1, string& word2, int i, int j, vector<vector<int>>& memo){
        if(j>=word2.size()){
            return word1.size()-i;
        }
        if(i>=word1.size()){
            return word2.size()-j;
        }
        if(word1[i]==word2[j]){
            return dp(word1, word2, i+1, j+1, memo);
        }
        if(memo[i][j]!=-1) return memo[i][j];
        int remove=1+dp(word1, word2, i+1, j, memo);
        int insert=1+dp(word1, word2, i, j+1, memo);
        int replace=1+dp(word1, word2, i+1, j+1, memo);

        return memo[i][j]=min(remove, min(insert, replace));
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
        return dp(word1, word2, 0, 0, memo);
    }
};
