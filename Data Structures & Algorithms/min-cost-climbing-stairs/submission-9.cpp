class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev=cost[1];
        int prev2=cost[0];
        int mini=0;

        for (int i = 2; i < n; i++) {
            mini = cost[i] + min(prev, prev2);
            prev2=prev;
            prev=mini;
        }

        // You can reach the top from either the last or second-to-last stair
        return min(prev, prev2);
    }
};