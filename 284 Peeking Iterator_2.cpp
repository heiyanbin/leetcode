// 284
// Peeking Iterator
// https://leetcode.com//problems/peeking-iterator/
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return current;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int ret = current;
	    if (Iterator::hasNext()) {
	        current = Iterator::next();
	        flag = true;
	    }
	    else flag = false;
	    return ret;
	}

	bool hasNext() const {
	    return flag;
	}
private:
    int current;
    bool flag;
};