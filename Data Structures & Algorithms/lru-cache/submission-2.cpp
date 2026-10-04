class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if (!address.count(key)) {
            return -1;
        }
        auto it = address[key];
        cache.splice(cache.begin(), cache, it);
        return it->second;
    }
    
    void put(int key, int value) {
        
        if(address.count(key)){
            auto it=address[key];
            it->second=value;
            cache.splice(cache.begin(), cache, it);
            return;
        }
        if(cache.size()==cap){
            address.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        address[key]=cache.begin();
        return;
    }

private:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> address;
    int cap;
};
