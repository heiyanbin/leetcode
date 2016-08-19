// 381
// Insert Delete GetRandom O(1) - Duplicates allowed
// https://leetcode.com//problems/insert-delete-getrandom-o1-duplicates-allowed/
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        a.push_back(val);
        pos[val].push_back(a.size() - 1);
        return pos[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (pos[val].empty()) return false;
        int i = pos[val].back();
        pos[val].pop_back();
        if (i < a.size() - 1) {
            swap(a[i], a.back());
    		a.pop_back();
    		pos[a[i]].back() = i;
        }
        else {
            a.pop_back();
        }
		return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int i = rand() % a.size();
        return a[i];
    }
private:
    vector<int> a;
    unordered_map<int, vector<int>> pos;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */