// 152
// Maximum Product Subarray
// https://leetcode.com//problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n<=0) return 0;
        int minP =A[0],maxP = A[0], maxProduct=A[0];
        for(int i=1;i<n;++i)
        {
            int tmpMinP= minP*A[i];
            int tmpMaxP= maxP*A[i];
            minP = min3(tmpMinP,tmpMaxP,A[i]);
            maxP = max3(tmpMinP,tmpMaxP,A[i]);
            maxProduct = max(maxProduct,maxP);
        }
        return maxProduct;
    }
    int min3(int a, int b, int c)
    {
        return min(min(a,b),c);
    }
    int max3(int a, int b, int c)
    {
        return max(max(a,b),c);
    }
    
};