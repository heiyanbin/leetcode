// 155
// Min Stack
// https://leetcode.com//problems/min-stack/
class MinStack {
public:
    void push(int x) {
        data.push(x);
        if(minS.empty()||x<=minS.top())
            minS.push(x);
    }

    void pop() {
        int x= data.top();
        data.pop();
        if(x==minS.top())
            minS.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minS.top();
    }
private:
    stack<int> data;
    stack<int> minS;
};