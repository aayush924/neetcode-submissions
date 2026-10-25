class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> change;
        for(int i=0;i<bills.size();i++){
            if(bills[i]!=5){
                if(bills[i]-5==5){
                    if(change[5]>0){
                        change[5]--;
                        change[10]++;
                    }
                    else return false;
                }
                else{
                    if(change[5]>0 && change[10]>0){
                        change[5]--;
                        change[10]--;
                    }
                    else if(change[5]>=3){
                        change[5]-=3;
                    }
                    else return false;
                }
            }
            else{
                change[5]++;
            }
        }
        return true;
    }
};