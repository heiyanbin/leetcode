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
        return cloneNode(node);
    }
    UndirectedGraphNode* cloneNode(UndirectedGraphNode *node) 
    {
        if(mp.find(node)!=mp.end()) return mp[node];
        mp[node]= new UndirectedGraphNode(node->label);
        for(auto neighbor : node->neighbors)
            mp[node]->neighbors.push_back(cloneNode(neighbor));
        return mp[node];
    }
    
private:
    map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
};