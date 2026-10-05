class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=0;
        int ans=0;
        while(r<prices.size()-1){
            r++;
            if(prices[r]<prices[l]){
                l=r;
            }
            
            else{
                int profit=prices[r]-prices[l];
                ans=max(ans, profit);
            }
        }
        return ans;
    }
};
