class Solution {
    int hours(vector<int>& piles, int h, int speed){
        int time=0;
        for(int& num: piles){
            if(num%speed!=0){
                time++;
            }
            time+=num/speed;
        }
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=0;
        for(int& num: piles){
            if(num>high) high=num;
        }
        int low=1;//mid=3
        while(low<high){
            int mid=(low+high)/2;
            int time=hours(piles, h, mid);
            if(time<=h){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
// mid:6
