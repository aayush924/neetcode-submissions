class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> unique;
        int n=s.size();
        int start=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(unique.find(s[i])!=unique.end() && unique[s[i]]>=start){
                start=unique[s[i]]+1;
                ans=max(i-start+1, ans);
                unique[s[i]]=i;
            }
            ans=max(i-start+1, ans);
            unique[s[i]]=i;
        } 
        return ans;
    }
};
