class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefMap;
        prefMap[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            count+=prefMap[sum-k];
            prefMap[sum]++;
        }
        return count;
    }
};