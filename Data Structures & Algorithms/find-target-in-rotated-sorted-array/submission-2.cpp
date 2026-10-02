class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;
        while(low<=high){
            int mid=(high+low)/2;
            if(target==nums[mid])return mid;

            if(nums[low]<=nums[mid]){
                //left half is sorted
                if(target<nums[mid] && target>=nums[low]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else {
                //right half is sorted
                if(target>nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
