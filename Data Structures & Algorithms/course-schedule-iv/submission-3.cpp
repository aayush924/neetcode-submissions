class Solution {
    void dfs(int u, 
             const vector<vector<int>>& adj, 
             vector<unordered_set<int>>& prereqs, 
             vector<bool>& visited) {
        if (visited[u]) return;
        visited[u] = true;

        for (int v : adj[u]) {
            dfs(v, adj, prereqs, visited);
            
            // v is a direct prerequisite
            prereqs[u].insert(v);
            // all prerequisites of v are also prerequisites of u
            prereqs[u].insert(prereqs[v].begin(), prereqs[v].end());
        }
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, 
                                     vector<vector<int>>& prerequisites, 
                                     vector<vector<int>>& queries) {
        // 1. Build a static adjacency list (u -> list of direct prerequisites)
        // edge [a, b] means a is a prerequisite of b: a -> b
        // Here adj[b] stores 'a' so we can traverse backwards from target to prerequisites
        vector<vector<int>> adj(numCourses);
        for (const auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        // 2. Track all prerequisites (direct + indirect) for each course
        vector<unordered_set<int>> prereqs(numCourses);
        vector<bool> visited(numCourses, false);

        for (int i = 0; i < numCourses; ++i) {
            dfs(i, adj, prereqs, visited);
        }

        // 3. Answer queries in O(1) average time each
        vector<bool> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            // q[0] is prerequisite of q[1] if it's in prereqs[q[1]]
            ans.push_back(prereqs[q[1]].contains(q[0]));
        }

        return ans;
    }
};