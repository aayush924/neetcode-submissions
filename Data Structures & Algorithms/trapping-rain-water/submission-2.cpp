class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int lmax=height[l];
        int rmax=height[r];
        int total=0;
        while(l<r){
            if(lmax<=rmax){
                l++;
                if(height[l]<lmax){
                    total+=lmax-height[l];
                } 
                else{
                    lmax=height[l];
                }
                
            }
            else{
                r--;
                if(height[r]<rmax) {
                    total+=rmax-height[r];
                }
                else rmax=height[r];
            }
        }
        return total;
    }
};
