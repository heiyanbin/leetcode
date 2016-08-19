// 59
// Spiral Matrix II
// https://leetcode.com//problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if(n==0) 
            return vector<vector<int>>();
        vector<vector<int>> output(n,vector<int>(n));
        int maxLevel = (n & 1)==0 ? n/2 :n/2+1;
        int val=1;
        for(int layer = 0; layer<maxLevel; layer++)
        {
            int k=layer;
            while(k<n-layer)
            {
                output[layer][k]=val++;
                k++;
            }
            k=layer+1;
            while(k<n-layer)
            {
                output[k][n-1-layer]=val++;
                k++;
            }
            if(n-1-layer!= layer)
            {
                k=n-2-layer;
                while(k>=layer)
                {
                    output[n-1-layer][k]=val++;
                    k--;
                }
            }
            k=n-2-layer;
            if(layer != n-1-layer)
            {
                 while(k>layer)
                {
                    output[k][layer]=val++;
                    k--;
                }
            }
        }
        return output;
    }
};