class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> valpos;
    vector<int> data;
    bool find(int val){
        return (valpos.find(val) != valpos.end());
    }
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        data.push_back(val);
        valpos[val].insert(data.size() - 1);
        return (valpos[val].size() == 1);
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // 没有 val
        if(!find(val)) return false;

        int _idx = *(valpos[val].begin());
        int _val = data.back();

        valpos[_val].insert(_idx);
        data[_idx] = _val;

        valpos[val].erase(_idx);
        if(valpos[val].size() == 0){
            valpos.erase(val);
        }

        data.pop_back();
        if(_idx < data.size()){
            valpos[_val].erase(data.size());
            valpos[_val].insert(_idx);
        }

        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return data[ rand() % data.size() ];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */