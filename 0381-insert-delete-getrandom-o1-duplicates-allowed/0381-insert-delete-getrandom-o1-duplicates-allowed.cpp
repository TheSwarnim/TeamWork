class RandomizedCollection {
public:
    unordered_map<int, set<int>> idxMap;
    vector<int> vals;
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        vals.push_back(val);
        idxMap[val].insert(vals.size()-1);
        return idxMap[val].size() == 1;
    }
    
    bool remove(int val) {
        if(idxMap.find(val) == idxMap.end()){
            return false;
        }
        
        if(vals.back() == val){
            // simple pop element
            vals.pop_back();
            if(idxMap[val].size() == 1){
                idxMap.erase(val);
            } else {
                idxMap[val].erase(prev(idxMap[val].end()));
            }
        } else {
            // shift the last value to a index and then of the given val
            set<int> &org = idxMap[val];
            set<int> &last = idxMap[vals.back()];
            
            // update indexes
            auto it = prev(org.end());
            auto it2 = prev(last.end());
            
            // update value in array
            last.erase(it2);
            last.insert(*it);
            vals[*it] = vals.back();
            
            if(idxMap[val].size() == 1){
                idxMap.erase(val);
            } else {
                org.erase(it);
            }
            vals.pop_back();
        }
        
        return true;
    }
    
    int getRandom() {
        return vals[rand()%vals.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */