// 14
// Longest Common Prefix
// https://leetcode.com//problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string output;
        if(strs.empty()) return output;
        bool allSame = true;
        int j=0;
        while(allSame)
        {
            allSame = true;
            int i=0;
            for(;i<strs.size()-1;i++)
            {
                if(j>=strs[i].size() || strs[i][j]!=strs[i+1][j])
                {
                    allSame = false;
                    break;
                }
            }
            if(allSame && j<strs[0].size())
            {
                output.push_back(strs[0][j]);
                j++;
            }
            else
                break;
        }
        return output;
    }
};