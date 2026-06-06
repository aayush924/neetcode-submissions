class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Build an adjacency list: u -> {v, weight}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // Min-heap: {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int> visited;
        
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            // If we already found the shortest path to this node, skip it
            if (visited.count(node)) continue;
            visited.insert(node);

            // If we've visited all nodes, this current time is the maximum delay time
            if (visited.size() == n) return time;

            // Explore neighbors efficiently
            for (auto& neighbor : adj[node]) {
                int next_node = neighbor.first;
                int weight = neighbor.second;
                if (!visited.count(next_node)) {
                    pq.push({time + weight, next_node});
                }
            }
        }

        return -1;
    }
};