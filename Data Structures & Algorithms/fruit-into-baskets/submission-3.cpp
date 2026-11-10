class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> types;
        //key=type, and value is last occurence
        int curr=0;
        int ans=INT_MIN;
        int start=0;
        int pos=INT_MAX;
        for(int i=0;i<fruits.size();i++){
            types[fruits[i]]=i;
            if(types.size()<=2){
                curr++;
                ans=max(curr, ans);
            }
            else{
                pos=INT_MAX;
                for(auto& [key, value]: types){
                    pos=min(value, pos);
                }
                for(auto& [key, value]: types){
                    if(pos==value){
                        types.erase(key);
                        break;
                    }
                }
                start=pos+1;
                curr=i-start+1;
                ans=max(curr, ans);
            }
        }
        return ans;
    }
};