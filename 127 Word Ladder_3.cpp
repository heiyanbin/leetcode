// 127
// Word Ladder
// https://leetcode.com//problems/word-ladder/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        q.push(start);
        int level =0;
        string levelEnd = start;
        unordered_set<string> visited;
        dict.insert(end);
        while(!q.empty())
        {
            string s = q.front();
            q.pop();
            if(s==end)
                return level+1;
            for(int i=0;i<s.size();i++)
            {
                char temp= s[i];
                for(char c= 'a';c<='z';c++)
                {
                    if(s[i]==c) continue;
                    s[i]=c;
                    if(dict.find(s)!=dict.end() && visited.find(s)==visited.end())
                    {
                        q.push(s);
                        visited.insert(s);
                    }
                }
                s[i]=temp;
            }
            if(s==levelEnd)
            {
                levelEnd = q.back();
                level++;
            }
        }
        return 0;
    }
};