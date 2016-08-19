// 210
// Course Schedule II
// https://leetcode.com//problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        for (auto &edge : prerequisites)
            G[edge.first].push_back(edge.second);
            
        vector<bool> marked(numCourses, false), inStack(numCourses, false);
        vector<int> res;
        
        for (int i = 0; i < numCourses; i++) {
            if (!marked[i]) 
                if (!dfs(G, i, marked, inStack, res))
                    return vector<int>();
        }
        return res;
    }
private:
    bool dfs(vector<vector<int>> &G, int s, vector<bool> &marked, vector<bool> &inStack, vector<int> &res) {
        marked[s] = true;
        inStack[s] = true;
        for (int adj : G[s]) {
            if (inStack[adj]) return false;
            if (!marked[adj] && !dfs(G, adj, marked, inStack, res)) return false;
        }
        res.push_back(s);
        inStack[s] = false;
        return true;
    }
};