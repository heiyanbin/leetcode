// 89
// Gray Code
// https://leetcode.com//problems/gray-code/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> output(1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=output.size()-1;j>=0;j--)
            {
                int highest_bit = 1<<i;
                output.push_back(highest_bit|output[j]);
            }
        }
        return output;
    }
};