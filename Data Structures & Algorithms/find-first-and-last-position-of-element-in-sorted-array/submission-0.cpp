class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;

        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                while(nums[l]!=target && l<=r) l++;
                while(nums[r]!=target && l<=r) r--;
                return {l, r};
            }
            else if(nums[m]>target){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return {-1, -1};

    }
};