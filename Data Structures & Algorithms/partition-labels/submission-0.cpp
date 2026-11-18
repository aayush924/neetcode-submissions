class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastInd;
        int n=s.size();
        for(int i=0;i<n;i++){
            lastInd[s[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int last=lastInd[s[i]];
            int start=i;
            while(i!=last){
                i++;
                last=max(last, lastInd[s[i]]);
            }
            ans.push_back(i-start+1);
        }
        return ans;
    }
};
