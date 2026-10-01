class DSU{
    int nodes;
    vector<int> size;
    vector<int> parent;

    public:
        DSU(int n){
            nodes=n;
            size.assign(nodes+1, 1);
            parent.assign(nodes+1, 0);
            for(int i=0;i<parent.size();i++){
                parent[i]=i;
            }
        }
        int UParent(int node){
            if(parent[node]==node) return node;
            return parent[node]=UParent(parent[node]);
        }
        bool add(vector<int>& edge){
            int uparent0=UParent(edge[0]);
            int uparent1=UParent(edge[1]);
            if(uparent0==uparent1) return false;
            if(size[uparent0]>=size[uparent1]){
                size[uparent0]+=size[uparent1];
                parent[uparent1]=uparent0;
            }
            else{
                size[uparent1]+=size[uparent0];
                parent[uparent0]=uparent1;
            }
            return true;
        }
};
class Solution {

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for(auto& edge: edges){
            if(!dsu.add(edge)){
                return edge;
            }
            
        }
        return {};
    }
};
