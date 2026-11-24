class Solution {
    int findDays(vector<int>& weights, int cap){
        int remain=cap;
        int ans=1;
        int i=0;
        while(i<weights.size()){
            if(weights[i]<=remain){
                remain-=weights[i];
            }
            else{
                remain=cap-weights[i];
                ans++;
            }
            i++;
        }
        return ans;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=-1;
        int high=0;
        for(int& num: weights){
            low=max(low, num);
            high+=num;
        }

        while(low<high){
            int mid=(low+high)/2;
            int temp=findDays(weights, mid);
            if(temp<=days){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};