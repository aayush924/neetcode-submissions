class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n): parent(n), size(n, 1){
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUparent(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=findUparent(parent[i]);
    }

    void merge(int u, int v){
        int uPar=findUparent(u);
        int vPar=findUparent(v);
        if(uPar==vPar) return;
        if(size[uPar]>=size[vPar]){
            parent[vPar]=uPar;
            size[uPar]+=size[vPar];
        }
        else{
            parent[uPar]=vPar;
            size[vPar]+=size[uPar];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string, int> emailIndMap;
        DSU dsu(n);

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string temp=accounts[i][j];
                if(!emailIndMap.count(temp)){
                    emailIndMap[accounts[i][j]]=i;
                }
                else{
                    dsu.merge(emailIndMap[temp], i);
                }
            }
        }

        vector<vector<string>> mergedEmail(n);
        for(auto& it: emailIndMap){
            int node=dsu.findUparent(it.second);
            mergedEmail[node].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedEmail[i].size()!=0){
                sort(mergedEmail[i].begin(), mergedEmail[i].end());
                vector<string> account;
                account.push_back(accounts[i][0]);
                for(auto& email: mergedEmail[i]){
                    account.push_back(email);
                }
                ans.push_back(account);
            }
        }
        return ans;
    }
};