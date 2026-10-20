class Solution {
    void dfs(vector<vector<int>>& prerequisites, int i, unordered_map<int, unordered_set<int>>& myMap, unordered_set<int>& visited){
        if(visited.contains(i)) return;
        for(auto& node: myMap[i]){
            dfs(prerequisites, node, myMap, visited);
            myMap[i].insert(myMap[node].begin(), myMap[node].end());
        }
        visited.insert(i);
        return;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> myMap;
        for(auto& prerequisite: prerequisites){
            myMap[prerequisite[1]].insert(prerequisite[0]);
        }
        unordered_set<int> visited;
        for(int i=0;i<numCourses;i++){
            dfs(prerequisites, i, myMap, visited);
        }

        vector<bool> ans;
        for(auto& query:queries){
            ans.push_back(myMap[query[1]].contains(query[0]));
        }
        return ans;
    }
};