class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        for (int i=0;i<n/2;i++){
            int temp=nums[i];
            nums[i]=nums[n-1-i];
            nums[n-1-i]=temp;
        }

        for(int i=0;i<k%n/2;i++){
            int temp=nums[i];
            nums[i]=nums[k%n-1-i];
            nums[k%n-1-i]=temp;
        }

        for(int i=k%n;i<(n+k%n)/2;i++){
            int temp=nums[i];
            nums[i]=nums[n+k%n-i-1];
            nums[n+k%n-i-1]=temp;
        }
        return;
    }
};