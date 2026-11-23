class MinStack {
    stack<int> nums;
    stack<int> decreasing;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        nums.push(val);
        if(decreasing.empty() || val<=decreasing.top()) decreasing.push(val);
        return;
    }
    
    void pop() {
        if(nums.top()==decreasing.top()){
            decreasing.pop();
        }
        nums.pop();
        return;
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return decreasing.top();
    }
};
