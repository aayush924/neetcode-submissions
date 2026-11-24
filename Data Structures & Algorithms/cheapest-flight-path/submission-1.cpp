class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> grid(n, vector<int>(n, INT_MAX));
        for (auto& flight : flights) {
            grid[flight[0]][flight[1]] = flight[2];
        }

        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        queue<pair<int, int>> q; // {node, current_cost}
        q.push({src, 0});
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int m = q.size();
            for (int i = 0; i < m; i++) {
                auto [source, currCost] = q.front();
                q.pop();

                for (int dest = 0; dest < n; dest++) {
                    if (grid[source][dest] == INT_MAX) continue;
                    
                    int nextCost = currCost + grid[source][dest];
                    if (nextCost < cost[dest]) {
                        cost[dest] = nextCost;
                        q.push({dest, nextCost});
                    }
                }
            }
            stops++;
        }

        return (cost[dst] < INT_MAX) ? cost[dst] : -1;
    }
};