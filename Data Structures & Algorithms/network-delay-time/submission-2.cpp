class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj(n+1, vector<int>(n+1, INT_MAX));
        for(auto& time: times){
            adj[time[0]][time[1]]=time[2];
        }
        //pair: dist, node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> network(n+1, INT_MAX);

        pq.push({0, k});
        network[k]=0;

        while(!pq.empty()){
            int src=pq.top().second;
            int dist=pq.top().first;
            
            for(int i=1;i<n+1;i++){
                if(adj[src][i]!=INT_MAX && adj[src][i]+dist<network[i]){
                    network[i]=adj[src][i]+dist;
                    pq.push({network[i], i});
                }
            }
            pq.pop();
        }
        int mini=0;
        for(int i=1;i<n+1;i++){
            mini=max(mini, network[i]);
        }
        return (mini==INT_MAX)? -1: mini;
    }
};
