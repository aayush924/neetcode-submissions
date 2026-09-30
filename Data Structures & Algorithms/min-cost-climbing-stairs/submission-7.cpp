class Solution {
    int recur(vector<int> cost, int i, vector<int>& memo){
        if(i>=cost.size()){
            return 0;
        }
        if(memo[i]!=-1) return memo[i];
        return memo[i]=cost[i]+min(recur(cost, i+1, memo), recur(cost, i+2, memo));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);
        return min(recur(cost, 0, memo), recur(cost, 1, memo));
    }
};
