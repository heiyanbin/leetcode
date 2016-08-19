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
        cloneNode(node);
        for(auto it= mp.begin();it!=mp.end();it++)
            for(auto neighbor : it->first->neighbors)
                it->second->neighbors.push_back(mp[neighbor]);
        return mp[node];
    }
    void cloneNode(UndirectedGraphNode *node) 
    {
        if(!node) return;
        mp[node]= new UndirectedGraphNode(node->label);
        for(auto neighbor : node->neighbors)
            if(!mp[neighbor])
                cloneNode(neighbor);
    }
    
private:
    map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
};