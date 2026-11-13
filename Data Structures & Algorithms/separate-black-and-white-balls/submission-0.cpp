class Solution {
public:
    long long minimumSteps(string s) {
        /*
        if we see a black, we keep its index in mind i
        when we see a white j, we will swap it but to swap we'll need j-i moves and i++
        */
        int i=0;
        long long ans=0;
        while(i<s.size() && s[i]!='1'){
            i++;
        }
        if(i==s.size()) return 0;

        for(int j=i+1;j<s.size();j++){
            if(s[j]=='0'){
                ans+=j-i;
                i++;
            }
        }
        return ans;
    }
};
