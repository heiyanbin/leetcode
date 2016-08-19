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
        unordered_map<string,unordered_set<string>> prev;
        queue<string> q;
        q.push(start);
        string levelEnd = start;
        bool found = false;
        
        while(!q.empty())
        {
            string s = q.front();
            q.pop();
            string s1(s);
            for(int i=0;i<s.size();i++)
            {
                char temp= s1[i];
                for(char c= 'a';c<='z';c++)
                {
                    if(s[i]==c)
                        continue;
                    s1[i]=c;
                    if(s1==end)
                    {
                        prev[s1].insert(s);
                        found = true;
                        break;
                    }
                    else if(dict.find(s1)!=dict.end() && (visited.find(s1)==visited.end()))
                    {
                        levelVisited.insert(s1);
                        prev[s1].insert(s);
                    }
                }
                s1[i]=temp;
            }
            
            if(s==levelEnd)
            {
                if(found)
                {
                    getPath(start,end,prev);
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
    void getPath(string start, string end, unordered_map<string, unordered_set<string>> &prev)
    {
        path.push_back(end);
        if(end==start)
        {
            output.push_back(vector<string>(path.rbegin(),path.rend()));
        }
        else
            for(auto e : prev[end])
                getPath(start,e, prev);
        path.pop_back();
    }
private:
    vector<vector<string>> output;
    vector<string> path;
};