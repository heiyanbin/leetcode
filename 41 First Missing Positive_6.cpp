// 41
// First Missing Positive
// https://leetcode.com//problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(!A||n<1) return 1;
        int min= INT_MAX, max=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(A[i]<=0) continue;
            if(A[i]>max) max=A[i];
            if(A[i]<min) min=A[i];
        }
        if(min>1) 
            return 1;
        int m= max-min+1;
        bool *b = new bool[m];
        memset(b,false,sizeof(bool)*m);
        for(int i=0;i<n;i++)
        {
            if(A[i]>0)
            {
                b[A[i]-min]=true;
            }
        }
        for(int i=1;i<m;i++)
        {
            if(!b[i])
                return i+min;
        }
        return max+1;
    }
};