class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for(char& c: s){
            freq[c]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>> maxH;
        for(auto& it: freq){
            maxH.push({it.second, it.first});
        }
        int n=s.size();
        if((n%2==0 && maxH.top().first>n/2) || (n%2!=0 && maxH.top().first>(n/2)+1)){
            return "";
        }
        string ans="";
        pair<int, char> curr={0, 'a'};
        pair<int, char> prev={0, 'a'};
        while(!maxH.empty() || prev.first>0){
            ans+=(maxH.top().second);
            curr=maxH.top();
            curr.first--;
            maxH.pop();
            if(prev.first>0) maxH.push(prev);
            prev=curr;
        }
        return ans;
    }
};