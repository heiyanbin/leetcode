// 133
// Clone Graph
// https://leetcode.com//problems/clone-graph/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode*node)
    {
        if(!node) return NULL;
        mp[node]= new UndirectedGraphNode(node->label);
        for(auto neighbor : node->neighbors)
            mp[node]->neighbors.push_back(mp.find(neighbor)==mp.end()?cloneGraph(neighbor):mp[neighbor]);
        return mp[node];
    }
private:
    map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
};