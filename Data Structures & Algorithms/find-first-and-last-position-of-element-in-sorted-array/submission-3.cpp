class Solution {
    int binarySearch(vector<int>& nums, int& target, bool isLeft){
        int l=0;
        int r=nums.size()-1;
        int i=-1;
        if(isLeft==true){
            while(l<=r){
                int m=l+(r-l)/2;
                if(nums[m]==target){
                    i=m;
                    r=m-1;
                }
                else if(nums[m]>target) {
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
        }
        else{
            while(l<=r){
                int m=l+(r-l)/2;
                if(nums[m]==target){
                    i=m;
                    l=m+1;
                }
                else if(nums[m]<target){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
        }
        return i;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
    }
};