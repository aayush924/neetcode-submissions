class Solution {
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph, string num, string& den, unordered_set<string>& visited){
        if(!graph.count(num)){
            return -1;
        }
        if(den==num) return 1;
        visited.insert(num);
        for(auto& node:graph[num]){
            if(visited.contains(node.first)){
                continue;
            }
            else if(node.first==den) return node.second;
            double temp=dfs(graph, node.first, den, visited);
            if(temp>=0){
                return node.second*temp;
            } 
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i=0;i<equations.size();i++){
            vector<string> equation=equations[i];
            graph[equation[0]].push_back({equation[1], values[i]});
            graph[equation[1]].push_back({equation[0], 1/values[i]});
        }
        
        vector<double> ans;
        
        for(int i=0;i<queries.size();i++){
            unordered_set<string> visited;
            vector<string> query=queries[i];
            string num=query[0];
            string den=query[1];
            ans.push_back(dfs(graph, num, den, visited));
        }
        return ans;
    }
};