// 225
// Implement Stack using Queues
// https://leetcode.com//problems/implement-stack-using-queues/
class Stack {
public:
    Stack() {
        p = &a;
        q = &b;
    }
    // Push element x onto stack.
    void push(int x) {
        p->push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(p->size() > 1) {
            q->push(p->front());
            p->pop();
        }
        p->pop();
        swap(p, q);
    }

    // Get the top element.
    int top() {
        while(p->size() > 1) {
            q->push(p->front());
            p->pop();
        }
        int ret = p->front();
        q->push(ret);
        p->pop();
        swap(p, q);
        return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        return p->empty();
    }
private:
    queue<int> *p, *q, a, b;
};