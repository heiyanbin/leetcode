// 385
// Mini Parser
// https://leetcode.com//problems/mini-parser/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
	NestedInteger deserialize(string s) {
		stack<NestedInteger*> stk;
		NestedInteger ni = NestedInteger();
		stk.push(&ni);
		for (int i = 0; i < s.size();) {
			if (s[i] == '[') {
				stk.top()->getList().push_back(NestedInteger());
				stk.push(&stk.top()->getList().back());
				++i;
			}
			else if (isdigit(s[i]) || s[i] == '+' || s[i] == '-') {
				int j = i + 1;
				for (; j < s.size() && isdigit(s[j]); ++j);
				stk.top()->getList().push_back(NestedInteger(stoi(s.substr(i, j - i))));
				i = j;
			}
			else if (s[i] == ']') {
				stk.pop();
				++i;
			}
			else ++i;
		}
		return stk.top()->getList().back();
	}
};