// 373
// Find K Pairs with Smallest Sums
// https://leetcode.com//problems/find-k-pairs-with-smallest-sums/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ans;
        if (nums1.empty() || nums2.empty()) return ans;
        
        typedef pair<int, pair<int, int>> P;
        priority_queue<P, vector<P>, greater<P>> pq;
        set<pair<int, int>> marked;
        
        pq.push(make_pair(nums1[0] + nums2[0], make_pair(0, 0)));
        marked.insert(make_pair(0, 0));
        
        for (; k > 0 && !pq.empty(); --k) {
            auto p = pq.top().second; pq.pop();
            int i = p.first, j = p.second;
            ans.push_back(make_pair(nums1[i], nums2[j]));
            
            auto down = make_pair(i + 1, j);
            if (i + 1 < nums1.size() && marked.find(down) == marked.end()) {
                marked.insert(down);
                pq.push(make_pair(nums1[i + 1] + nums2[j], down));
            }
            
            auto right = make_pair(i, j + 1);
            if (j + 1 < nums2.size() && marked.find(right) == marked.end()) {
                marked.insert(right);
                pq.push(make_pair(nums1[i] + nums2[j + 1], right));
            }
        }
        
        return  ans;
    }
};