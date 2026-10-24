#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Base case: If there are <= 2 nodes, all of them are valid roots
        if (n <= 2) {
            vector<int> res;
            for (int i = 0; i < n; i++) res.push_back(i);
            return res;
        }

        // Build adjacency list and compute degrees
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        // Push all initial leaves (degree == 1) into the queue
        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }

        // Trim leaves layer-by-layer until 1 or 2 nodes remain
        int remaining_nodes = n;
        while (remaining_nodes > 2) {
            int leaf_count = leaves.size();
            remaining_nodes -= leaf_count;

            for (int i = 0; i < leaf_count; i++) {
                int leaf = leaves.front();
                leaves.pop();

                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        // The remaining nodes in the queue are the MHT roots
        vector<int> ans;
        while (!leaves.empty()) {
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};