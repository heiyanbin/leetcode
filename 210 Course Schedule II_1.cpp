// 210
// Course Schedule II
// https://leetcode.com//problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        for (auto &edge : prerequisites)
            G[edge.first].push_back(edge.second);
            
        vector<int> marked(numCourses, 0);
        vector<int> res;
        
        for (int i = 0; i < numCourses; i++) {
            if (marked[i] == 0 && !dfs(G, i, marked, res))
                    return vector<int>();
        }
        return res;
    }
private:
    bool dfs(vector<vector<int>> &G, int s, vector<int> &marked, vector<int> &res) {
        marked[s] = 2; //2 means marked and in stack
        for (int adj : G[s]) {
            if (marked[adj] == 2 || marked[adj] == 0 && !dfs(G, adj, marked, res)) return false;
        }
        res.push_back(s);
        marked[s] = 1; //1 means marked 
        return true;
    }
};