// 341
// Flatten Nested List Iterator
// https://leetcode.com//problems/flatten-nested-list-iterator/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        _list = &nestedList;
        _index = 0;
    }

    int next() {
        return (*_list)[_index++].getInteger();
    }

    bool hasNext() {
        while (!_stack.empty() || _index < _list->size()) {
            if (_index < _list->size() ) {
                if ((*_list)[_index].isInteger()) return true;
                else {
                    _stack.push(make_pair(_list, _index));
                    _list = &((*_list)[_index].getList());
                    _index = 0;
                }
            }
            else {
                _list = _stack.top().first;
                _index = _stack.top().second + 1;
                _stack.pop();
            }
        }
        return false;
    }
private:
    vector<NestedInteger> *_list;
    int _index ;
    stack<pair<vector<NestedInteger>*, int>> _stack;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */