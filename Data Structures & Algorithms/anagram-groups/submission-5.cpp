class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (const string& s : strs) {
            // A fixed 26-char string where each byte stores the character count directly
            string key(26, 0);
            for (char c : s) {
                key[c - 'a']++;
            }
            res[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& [key, group] : res) {
            result.push_back(group);
        }

        return result;
    }
};