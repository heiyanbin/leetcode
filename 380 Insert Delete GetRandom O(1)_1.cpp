// 380
// Insert Delete GetRandom O(1)
// https://leetcode.com//problems/insert-delete-getrandom-o1/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = pos.find(val);
        if (it != pos.end()) return false;
        a.push_back(val);
        pos[val] = a.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = pos.find(val);
        if (it == pos.end()) return false;
        int i = it->second;
        swap(a[a.size() - 1], a[i]);
        a.pop_back();
        pos.erase(it);
        if (i < a.size())
            pos[a[i]] = i;
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % a.size();
        return a[r];
    }
private:
    unordered_map<int, int> pos;
    vector<int> a;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */