// 347
// Top K Frequent Elements
// https://leetcode.com//problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto num : nums) m[num]++;
        
        priority_queue<pair<int, int>> pq;
        for (auto p : m) pq.push({p.second, p.first});
        
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};