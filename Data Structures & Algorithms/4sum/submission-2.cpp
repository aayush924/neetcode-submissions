class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        int i=0;
        while(i<n-3){
            int j=i+1;
            while(j<n-2){
                int l=j+1;
                int r=n-1;
                while(l<r){
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum==target){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        ans.push_back(temp);
                        temp.clear();
                        l++;
                        r--;
                        while(nums[l]==nums[l-1] && l<r) l++;
                        while(nums[r]==nums[r+1] && l<r) r--;
                    }
                    else if(sum<target){
                        l++;
                    }
                    else{
                        r--;
                        
                    }
                }
                j++;
                while(nums[j]==nums[j-1] && j<n-2) j++;
            }
            i++;
            while(nums[i]==nums[i-1] && i<n-3) i++;
        }
        return ans;
    }
};