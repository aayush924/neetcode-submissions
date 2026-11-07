class TimeMap {
    unordered_map<string, vector<pair<int, string>>> hMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hMap[key].push_back({timestamp, value});
        return;
    }
    
    string get(string key, int timestamp) {
        auto& temp=hMap[key];
        int l=0, r=temp.size()-1;
        string ans="";
        while(l<=r){
            int m=(l+r)/2;
            if(temp[m].first>timestamp){
                r=m-1;
            }
            else{
                ans=temp[m].second;
                l=m+1;
            }
        }
        return ans;
    }
};
