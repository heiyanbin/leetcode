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
        for(map<UndirectedGraphNode*,UndirectedGraphNode*>::iterator it= mp.begin();it!=mp.end();it++)
        {
            for(int i=0;i<it->first->neighbors.size();i++)
                it->second->neighbors.push_back(mp[it->first->neighbors[i]]);
        }
        return mp[node];
    }
    void cloneNode(UndirectedGraphNode *node) 
    {
        if(!node) return;
        mp[node]= new UndirectedGraphNode(node->label);
        for(int i=0;i<node->neighbors.size();i++)
        {
            if(!mp[node->neighbors[i]])
                cloneNode(node->neighbors[i]);
        }
    }
    
private:
    map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
};