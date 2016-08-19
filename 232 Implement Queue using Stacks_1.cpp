// 232
// Implement Queue using Stacks
// https://leetcode.com//problems/implement-queue-using-stacks/
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if (s2.empty()) {
            for (; s1.size() > 0; s2.push(s1.top()), s1.pop()) ;
        }
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1, s2;
};