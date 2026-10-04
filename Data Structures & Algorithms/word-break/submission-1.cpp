class Solution {
    bool check(string s, vector<string>& wordDict, int ind, vector<int>& dp){
        if(ind>=s.size()) return true;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(auto& word: wordDict){
            if(word[0]==s[ind]){
                int i=0;
                while(i<word.size() && word[i]==s[ind+i]){
                    i++;
                }
                if(i==word.size()){
                    if(check(s, wordDict, ind+i, dp)){
                        return dp[ind]=1;
                    }
                }
            }    
        }
        return dp[ind]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return check(s, wordDict, 0, dp);
    }
};
