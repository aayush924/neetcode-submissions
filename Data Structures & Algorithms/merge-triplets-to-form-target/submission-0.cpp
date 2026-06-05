class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first=false;
        bool second=false;
        bool third=false;

        for(auto& triplet: triplets){
            if(first && second && third){
                return true;
            }
            if(triplet[0]<=target[0] && triplet[1]<=target[1] && triplet[2]<=target[2]){
                first |= (triplet[0]==target[0]);
                second |= (triplet[1]==target[1]);
                third |= (triplet[2]==target[2]);
            }
        }
        return (first && second && third);
    }
};
