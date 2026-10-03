class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;

        // 1. Build Adjacency Matrix
        vector<vector<int>> adjacency(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adjacency[i][j] = dist;
                adjacency[j][i] = dist; // Symmetric matrix: saves half the calculations
            }
        }

        // 2. Prim's Algorithm without Priority Queue
        vector<int> min_dist(n, 1e9);
        vector<bool> in_mst(n, false);

        min_dist[0] = 0;
        int total_cost = 0;

        for (int step = 0; step < n; ++step) {
            int u = -1;

            // Pick the unvisited node closest to the current MST
            for (int i = 0; i < n; ++i) {
                if (!in_mst[i] && (u == -1 || min_dist[i] < min_dist[u])) {
                    u = i;
                }
            }

            in_mst[u] = true;
            total_cost += min_dist[u];

            // Update candidate distances using the precomputed matrix
            for (int v = 0; v < n; ++v) {
                if (!in_mst[v] && adjacency[u][v] < min_dist[v]) {
                    min_dist[v] = adjacency[u][v];
                }
            }
        }

        return total_cost;
    }
};