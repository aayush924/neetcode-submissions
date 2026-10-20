class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> q;
        if(visited.contains("0000")) return -1;
        q.push("0000");
        visited.insert("0000");
        int turns=-1;
        while(!q.empty()){
            int n=q.size();
            turns++;
            for(int i=0;i<n;i++){
                string curr=q.front();
                if(curr==target) return turns;
                for(int j=0;j<4;j++){
                    int currDigi=curr[j]-'0';
                    string temp=curr;
                    char charac='0'+(currDigi+1)%10;
                    temp[j]=charac;
                    if(!visited.contains(temp)) {
                        q.push(temp);
                        visited.insert(temp);
                    }

                    temp=curr;
                    charac='0'+(currDigi-1+10)%10;
                    temp[j]=charac;
                    if(!visited.contains(temp)) {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};