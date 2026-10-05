class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lMax=height[0];
        int rMax=height[n-1];

        int l=0;
        int r=n-1;
        int ans=0;
        while(l<r){
            if(lMax<=rMax){
                l++;
                if(height[l]<lMax){
                    ans+=lMax-height[l];
                }
                else{
                    lMax=height[l];
                }
            }
            else{
                r--;
                if(height[r]<rMax){
                    ans+=rMax-height[r];
                }
                else{
                    rMax=height[r];
                }
            }
        }
        return ans;
    }
};
