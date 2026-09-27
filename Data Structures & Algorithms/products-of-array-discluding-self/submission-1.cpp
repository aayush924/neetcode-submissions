class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int n=nums.size();
        vector<int> arr(n);
        arr[n-1]=1;
        for(int i=n-2;i>=0;i--){
            arr[i]=nums[i+1]*arr[i+1];
        }
        for(int i=0;i<n;i++){
            arr[i]=prod*arr[i];
            prod*=nums[i];
        }
        return arr;
    }
};
