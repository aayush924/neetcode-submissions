class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size();//cols
        for(int i=matrix.size()-1;i>=0;i--){
            if(target>=matrix[i][0]){
                if(target>matrix[i][n-1]){
                    return false;
                }
                vector<int> row=matrix[i];
                int low=0;
                int high=n-1;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(row[mid]>target){
                        high=mid-1;
                    }
                    else if(row[mid]<target){
                        low=mid+1;
                    }
                    else{
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
