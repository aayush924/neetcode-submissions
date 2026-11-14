class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        string ans="";
            
        int m=strs[0].size();
        for(int i=0;i<m;i++){
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j].size()==i || strs[j][i]!=c) return ans;
            }
            ans+=c;
        }
        return ans;
    }
};