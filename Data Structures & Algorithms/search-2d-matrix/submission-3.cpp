class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();//rows
        int n=matrix[0].size();//cols
        int l=0;
        int h=m*n-1;
        while(l<=h){
            int mid=(l+h)/2;
            int val=matrix[mid/n][mid%n];
            if(val<target){
                l=mid+1;
            }
            else if(val>target){
                h=mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
