// 27
// Remove Element
// https://leetcode.com//problems/remove-element/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i=0;
        for(int j=0;j<n;j++)
        {
            if(A[j]!=elem)
            {
                A[i]=A[j];
                i++;
            }
        }
        return i;
    }
};