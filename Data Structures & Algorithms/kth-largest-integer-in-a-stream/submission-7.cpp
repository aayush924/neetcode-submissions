class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int capacity;
public:
    KthLargest(int k, vector<int>& nums) {
        capacity=k;
        for(int num: nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>capacity){
            pq.pop();
        }
        return pq.top();
    }
};
