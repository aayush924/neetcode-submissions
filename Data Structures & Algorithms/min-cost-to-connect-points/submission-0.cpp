class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> adjacency(n, vector<int>(n, 0));

        for(int i=0;i<n;i++){
            int j=0;
            while(j<n){
                if(j==i) {
                    j++;
                    continue;
                }
                adjacency[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                j++;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minH;
        unordered_set<int> visited;
        visited.insert(0);
        int cost=0;
        int i=0;
        while(visited.size()!=n){
            for(int j=0;j<n;j++){
                if(!visited.contains(j)){
                    minH.push({adjacency[i][j], j});
                }
            }
            while (!minH.empty() && visited.count(minH.top().second)) {
                minH.pop();
            }
            i=minH.top().second;
            visited.insert(minH.top().second);
            cost+=minH.top().first;
            minH.pop();
        }
        return cost;
    }
};
