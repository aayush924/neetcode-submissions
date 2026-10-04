class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> count;
        for(int i=0;i<hand.size();i++){
            count[hand[i]]++;
        }

        for(int& num: hand){
            if(count[num]!=0){
                count[num]--;
                for(int j=num+1;j<num+groupSize;j++){
                    if(count[j]==0) return false;
                    count[j]--;
                }
            }
        }
        return true;
    }
};
//1,2,3,3,4,5