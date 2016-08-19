// 96
// Unique Binary Search Trees
// https://leetcode.com//problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        
        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= i; k++) //iterate the case k(1..i) as the root
                f[i] += f[k - 1] * f[i - k];
                
        return f[n];
    }
};