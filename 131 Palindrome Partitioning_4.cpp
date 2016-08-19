// 131
// Palindrome Partitioning
// https://leetcode.com//problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) 
            return output;
        DFS(s,0);
        return output;
    }
    void DFS(string &s, int i)
    {
        if(i>s.size()-1)
        {
            output.push_back(path);
            return;
        }
        for(int k=i;k<s.size();k++)
        {
            if(isPalindrome(s,i,k))
            {
                path.push_back(string(s.begin()+i,s.begin()+k+1));
                DFS(s,k+1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string &s, int begin, int end)
    {
        int i=begin,j=end;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
private:
    vector<string> path;
    vector<vector<string>> output;
    
};