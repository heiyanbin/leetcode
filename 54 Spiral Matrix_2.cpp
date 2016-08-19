// 54
// Spiral Matrix
// https://leetcode.com//problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> output;
        int m= matrix.size();
        if(m<1) return output;
        int n= matrix[0].size();
        if(n<1) return output;
        int l = min (m,n);
        int maxLayer = (l&1)==0 ? l/2 : l/2+1;
        for(int layer=0;layer<maxLayer;layer++)
        {
            int k=layer;
            while(k<n-layer)
            {
                output.push_back(matrix[layer][k]);
                k++;
            }
            k=layer+1;
            while(k<m-layer)
            {
                output.push_back(matrix[k][n-1-layer]);
                k++;
            }
            if(m-1-layer!= layer)
            {
                k=n-2-layer;
                while(k>=layer)
                {
                    output.push_back(matrix[m-1-layer][k]);
                    k--;
                }
            }
            k=m-2-layer;
            if(layer != n-1-layer)
            {
                 while(k>layer)
                {
                    output.push_back(matrix[k][layer]);
                    k--;
                }
            }
        }
        return output;
    }
};