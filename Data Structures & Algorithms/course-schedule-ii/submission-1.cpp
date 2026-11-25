class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> dependents(numCourses);
        for(auto& it: prerequisites){
            adj[it[1]].push_back(it[0]);
            dependents[it[0]]++;
        }

        queue<int> q;
        stack<int> st;
        for(int i=0;i<numCourses;i++){
            if(dependents[i]==0) q.push(i); 
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            st.push(node);
            for(auto& it: adj[node]){
                dependents[it]--;
                if(dependents[it]==0) q.push(it);
            }
        }

        for(auto& it: dependents){
            if(it!=0) return {};
        }
        vector<int> ans(numCourses);
        for(int i=numCourses-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};
