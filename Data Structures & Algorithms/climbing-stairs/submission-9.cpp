class Solution {
    int recur(int n, vector<int>& memo){
        if(n<=1) return 1;
        if(memo[n]!=0) return memo[n];
        return memo[n]=recur(n-1, memo)+recur(n-2, memo);

    }
public:
    int climbStairs(int n) {
        vector<int> memo(n+1, 0);
        memo[0]=1;
        memo[1]=1;
        return recur(n, memo);
    }
};
