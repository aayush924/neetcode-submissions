class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> unique;
        int l=0, longest=0, r=0;

        while(r<s.size()){
            if (unique.find(s[r]) != unique.end()) {
                l = max(unique[s[r]] + 1, l);
            }
            unique[s[r]] = r;
            longest = max(longest, r - l + 1);
            r++;
        }
        return longest;
    }
};
