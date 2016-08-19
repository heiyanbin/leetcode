// 295
// Find Median from Data Stream
// https://leetcode.com//problems/find-median-from-data-stream/
class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (left_heap.size() > 0 && num >= left_heap.top()) {
            right_heap.push(num);
            if (right_heap.size() - left_heap.size() > 1) {
               left_heap.push(right_heap.top());
               right_heap.pop();
            }
        }
        else {
            left_heap.push(num);
            if (left_heap.size() - right_heap.size() > 1) {
                right_heap.push(left_heap.top());
                left_heap.pop();
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (left_heap.size() > right_heap.size()) return left_heap.top();
        if (left_heap.size() < right_heap.size()) return right_heap.top();
        return (left_heap.top() + right_heap.top()) / 2.0;
    }
private:
    priority_queue<int> left_heap;
    priority_queue<int, vector<int>, greater<int>> right_heap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();