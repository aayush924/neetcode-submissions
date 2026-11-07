class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        string ans(n, ' ');
        pair<int, int> maxf={0, 0}; //first=index, second=freq
        vector<int> freq(26, 0);

        for(char& c: s){
            freq[c-'a']++;
            if(freq[c-'a']>maxf.second){
                maxf={c-'a', freq[c-'a']};
            }
        }

        if(maxf.second>(n+1)/2){
            return "";
        }

        int idx=0;
        while(freq[maxf.first]>0){
            ans[idx]='a'+maxf.first;
            freq[maxf.first]--;
            idx+=2;
        }

        for(int i=0;i<26; i++){
            while(freq[i]>0){
                if(idx>=s.size()) idx=1;
                ans[idx]='a'+i;
                freq[i]--;
                idx+=2;
            }
        }
        return ans;
    }
};