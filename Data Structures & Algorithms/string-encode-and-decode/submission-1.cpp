class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string& str: strs){
            encoded+=to_string(str.size())+ '#'+ str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string length="";
        int i=0;
        while(i<s.size()){
            while(s[i]!='#'){
                length+=s[i];
                i++;
            }
            i++;
            ans.push_back(s.substr(i, stoi(length)));
            i+=stoi(length);
            length="";
        }
        return ans;
    }
};
