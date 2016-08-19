// 127
// Word Ladder
// https://leetcode.com//problems/word-ladder/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start==end) return 0;
        queue<string> q;
        q.push(start);
        int level =1;
        string levelEnd = start;
        unordered_set<string> visited;
        while(!q.empty())
        {
            string s = q.front();
            q.pop();
            for(int i=0;i<s.size();i++)
            {
                char temp= s[i];
                for(char c= 'a';c<='z';c++)
                {
                    if(s[i]==c) continue;
                    s[i]=c;
                    if(s==end) return level+1;
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