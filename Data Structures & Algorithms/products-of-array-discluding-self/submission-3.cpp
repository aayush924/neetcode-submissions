class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        // vector<int> prefix(n, 1);
        // vector<int> suffix(n, 1);

        // for(int i=0;i<n;i++){
        //     if(i!=0) {
        //         prefix[i]=prefix[i-1]*nums[i-1]; 
        //         suffix[n-i-1]=suffix[n-i]*nums[n-i];
        //     }
        // }
        // int prefix=0;
        // int suffix=0;

        vector<int> ans(n, 1);
        
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=suffix;
            suffix*=nums[i];
        }
        return ans;
    }
};
