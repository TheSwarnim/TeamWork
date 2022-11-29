class RandomizedSet {
public:
    unordered_map<int, int> idxMap;
    vector<int> vals;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(idxMap.count(val)){
            return 0;
        }    
        
        vals.push_back(val);
        idxMap[val] = vals.size() -1;
        return 1;
    }
    
    bool remove(int val) {
        if(!idxMap.count(val)){
            return 0;
        }
        
        // replace the idx of last element to the current idx
        int idx = idxMap[val];
        idxMap[vals[vals.size()-1]] = idx;
        idxMap.erase(val);
        vals[idx] = vals[vals.size()-1];
        vals.pop_back();
        return 1;
    }
    
    int getRandom() {
        int idx = (rand()%vals.size());
        return vals[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */