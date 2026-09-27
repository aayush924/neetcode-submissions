class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> groups;
        vector<int> anagram(26, 0);
        for(string str: strs){
            for(char c: str){
                anagram[c-'a']++;
            }
            groups[anagram].push_back(str);
            fill(anagram.begin(), anagram.end(), 0);
        }

        vector<vector<string>> ans;
        for(const auto& [key, value] : groups){
            ans.push_back(value);
        }
        return ans;
    }
};
