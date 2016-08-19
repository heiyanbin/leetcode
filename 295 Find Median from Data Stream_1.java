// 295
// Find Median from Data Stream
// https://leetcode.com//problems/find-median-from-data-stream/
class MedianFinder {

    // Adds a number into the data structure.
    public void addNum(int num) {
        if (L.size() > 0 && num >= L.peek()) {
            R.offer(num);
            if (R.size() - L.size() > 1) L.offer(R.poll());
        }
        else {
            L.offer(num);
            if (L.size() - R.size() > 1) R.offer(L.poll());
        }
    }

    // Returns the median of current data stream
    public double findMedian() {
        if (L.size() > R.size()) return L.peek();
        if (L.size() < R.size()) return R.peek();
        return (L.peek() + R.peek()) / 2.0;
    }
    private PriorityQueue<Integer> L = new PriorityQueue<Integer>(11, new Comparator<Integer>() {
        public int compare(Integer a, Integer b) { return b - a; }
    });
    private PriorityQueue<Integer> R = new PriorityQueue<Integer>();
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf = new MedianFinder();
// mf.addNum(1);
// mf.findMedian();