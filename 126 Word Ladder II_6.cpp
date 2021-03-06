// 126
// Word Ladder II
// https://leetcode.com//problems/word-ladder-ii/
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        size_t len = start.size();
        if (len != end.size() || len == 0 || start == end) 
            return output;

        unordered_set<string> visited;
        unordered_set<string> levelVisited;
        dict.erase(start);
        dict.insert(end);
        unordered_map<string,vector<string>> parent;
        queue<string> q;
        q.push(start);
        string levelEnd = start;
        bool found = false;
        
        while(!q.empty())
        {
            string s = q.front();
            q.pop();
            string s1(s);
            for(int i=0;i<s1.size();i++)
            {
                char temp= s1[i];
                for(char c= 'a';c<='z';c++)
                {
                    if(s1[i]==c)
                        continue;
                    s1[i]=c;
                    if(s1==end)
                    {
                        parent[s1].push_back(s);
                        found = true;
                        break;
                    }
                    else if(dict.find(s1)!=dict.end() && (visited.find(s1)==visited.end()))
                    {
                        levelVisited.insert(s1);
                        parent[s1].push_back(s);
                    }
                }
                s1[i]=temp;
            }
            
            if(s==levelEnd)
            {
                if(found)
                {
                    getPath(start,end,parent);
                    break;
                }
                for(auto e: levelVisited)
                {
                    q.push(e);
                    visited.insert(e);
                }
                levelVisited.clear();
                if(!q.empty())
                    levelEnd=q.back();
            }
        }
        return output;
    }
    void getPath(const string &start, string end, unordered_map<string, vector<string>> &parent)
    {
        path.push_back(end);
        if(end==start)
            output.push_back(vector<string>(path.rbegin(),path.rend()));
        else
            for(auto e : parent[end])
                getPath(start,e, parent);
        path.pop_back();
    }
private:
    vector<vector<string>> output;
    vector<string> path;
};