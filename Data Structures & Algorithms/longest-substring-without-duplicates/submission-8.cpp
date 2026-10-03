class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        int longest=0;
        int n=s.size();
        unordered_map<char, int> myMap;
        while(r<n){
            if(!myMap.count(s[r]) || myMap[s[r]]<l){
                myMap[s[r]]=r;
            }
            else{
                longest=max(longest, r-l);
                l=myMap[s[r]]+1;
                myMap[s[r]]=r;
            }
            r++;
        }
        return max(longest, r-l);
    }
};
