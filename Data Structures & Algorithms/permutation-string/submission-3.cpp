class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> chars1(26, 0);
        vector<int> empty(26, 0);
        vector<int> chars2=empty;

        for(char& c: s1){
            chars1[c-'a']++;
        }

        for(int i=0;i<s2.size();i++){
            if(chars1[s2[i]-'a']>chars2[s2[i]-'a']){
                int j=i;
                while(j<s2.size() && chars1[s2[j]-'a']>chars2[s2[j]-'a']){
                    chars2[s2[j]-'a']++;
                    if(chars1==chars2)return true;
                    j++;
                }
                chars2=empty;
            }
        }
        return false;
    }
};
