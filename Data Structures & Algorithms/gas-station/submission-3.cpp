class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sumG=0;
        int sumC=0;
        vector<int> diff;
        for(int i=0;i<n;i++){
            sumG+=gas[i];
            sumC+=cost[i];
            diff.push_back(gas[i]-cost[i]);
        }
        if(sumC>sumG) return -1;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum<0) {
                sum=0;
                ans=i+1;
            }
        }
        return ans;
    }
};
