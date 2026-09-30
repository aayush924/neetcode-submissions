class Solution {
    int recur(string s, int i, vector<int>& memo){
        if(i==s.size()) return 1;
        if(s[i]=='0'){
            return 0;
        }
        if(memo[i]!=-1) return memo[i];
        int left=recur(s, i+1, memo);
        int right=0;
        if(i<s.size()-1 && stoi(s.substr(i, 2))<=26){
            right=recur(s, i+2, memo);
        }
        return memo[i]=left+right;
    }
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        vector<int> memo(s.size(), -1);
        return recur(s, 0, memo);
    }
};
