class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(') left.push(i);
            else if(s[i]=='*') star.push(i);
            else{
                if(left.empty() && star.empty()) return false;
                else if(!left.empty()) left.pop();
                else star.pop();
            }
        }
        while(!left.empty() && !star.empty()){
            if(star.top()>left.top()){
                star.pop();
                left.pop();
            }
            else return false;
        }
        return left.empty();
    }
};
