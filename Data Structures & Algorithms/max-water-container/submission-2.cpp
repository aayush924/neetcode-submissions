class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int n=heights.size();
        int r =n-1;
        int maxi=INT_MIN;

        while(l<r){
            maxi=max(maxi, (r-l)*min(heights[r], heights[l]));
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return maxi;
    }
};
