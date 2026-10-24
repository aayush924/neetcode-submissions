class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> heights(n, 0);
        unordered_set<int> visited;
        queue<int> q;
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int root=0;root<n;root++){
            visited.clear();
            q.push(root);
            int level=0;
            while(!q.empty()){
                int qn=q.size();
                for(int i=0;i<qn;i++){
                    int node=q.front();
                    q.pop();
                    visited.insert(node);
                    for(auto& it: adj[node]){
                        if(!visited.contains(it)){
                            q.push(it);
                        }
                    }
                }
                level++;
            }
            heights[root]=level;
        }
        int minH=INT_MAX;
        for(auto& num: heights){
            if(num<minH){
                minH=num;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(heights[i]==minH){
                ans.push_back(i);
            }
        }
        return ans;
    }
};