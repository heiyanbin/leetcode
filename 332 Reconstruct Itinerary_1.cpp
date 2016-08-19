// 332
// Reconstruct Itinerary
// https://leetcode.com//problems/reconstruct-itinerary/
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> G;
        for (auto &ticket : tickets) {
            G[ticket.first].push(ticket.second);
        }
        
        vector<string> path;
        function<void(string)> dfs = [&](string v) {
                auto & edges = G[v];
                while (edges.size() > 0) {
                    string to = edges.top(); edges.pop();
                    dfs(to);
                }
                path.push_back(v);
        };
        
        dfs("JFK");
        reverse(path.begin(), path.end());
        return path;
    }
    
};