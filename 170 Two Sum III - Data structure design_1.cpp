// 170
// Two Sum III - Data structure design
// https://leetcode.com//problems/two-sum-iii-data-structure-design/
class TwoSum {
public:
	void add(int number) {
	    m[number]++;
	}

	bool find(int value) {
	    for (auto &e : m) {
            if (value - e.first != e.first) {
                if (m.find(value - e.first) != m.end()) return true;
            }
	        else if (e.second > 1) 
                return true;
	    }
        return false;
	}
private:
    unordered_map<int, int> m;
    vector<int> A;
};