class RandomizedSet {
    unordered_map<int, int> lookup;
    vector<int> randomSet;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(lookup.count(val)) return false;
        randomSet.push_back(val);
        lookup[val]=randomSet.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!lookup.count(val)) return false;
        int ind=lookup[val];
        int temp=randomSet[randomSet.size()-1];
        randomSet[ind]=temp;
        lookup[temp]=ind;
        lookup.erase(val);
        randomSet.pop_back();
        return true;
    }
    
    int getRandom() {
        return randomSet[rand() % randomSet.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */