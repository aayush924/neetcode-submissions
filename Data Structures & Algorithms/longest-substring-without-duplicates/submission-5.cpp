class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unique;
        int l=0, r=0;
        int longest=0;
        int ans=0;
        while(r<s.size()){
            if(!unique.contains(s[r])){
                longest++;
                unique.insert(s[r]);
                r++;
                continue;
            }
            ans=max(longest, ans);
            while(s[l]!=s[r]){
                unique.erase(s[l]);
                l++;
            }
            l++;
            longest=r-l+1;
            r++;
        }

        return max(ans, longest);
    }
};
