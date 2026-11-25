class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> network(n + 1, INT_MAX);

        network[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [dist, src] = pq.top();
            pq.pop(); // Pop immediately before pushing anything new

            if (dist > network[src]) continue; // Skip stale heap entries

            for (const auto& [dest, weight] : adj[src]) {
                if (dist + weight < network[dest]) {
                    network[dest] = dist + weight;
                    pq.push({network[dest], dest});
                }
            }
        }

        int mini=0;
        for(int i=1;i<n+1;i++){
            mini=max(mini, network[i]);
        }
        return (mini==INT_MAX)? -1: mini;
    }
};
        
