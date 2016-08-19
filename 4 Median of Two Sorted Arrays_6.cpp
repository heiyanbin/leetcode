// 4
// Median of Two Sorted Arrays
// https://leetcode.com//problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m<=0) return mid(B,n);
        if(n<=0) return mid(A,m);
        if(m>n) return findMedianSortedArrays(B,n,A,m);
        if(m==1)
        {
            return mid2(A[0],B,n);
        }
        if(A[0]<=B[0] && A[m-1]>=B[n-1])
            return findMedianSortedArrays(&A[1],m-2,B,n);
        else if (B[0]<=A[0] && B[n-1]>=A[m-1])
            return findMedianSortedArrays(A,m, &B[1],n-2);

        double aMid = mid(A,m);
        double bMid = mid(B,n);
        if(aMid==bMid) 
            return aMid;
        else if(aMid<bMid)
        {
            if((m&1)==0 && m!=2)
                return findMedianSortedArrays(&A[m/2-1],m-(m/2-1), B, n-(m/2-1));
            else
                return findMedianSortedArrays(&A[m/2],m-m/2, B, n-m/2);
        }
        else
        {
            if(m!=2)
                return findMedianSortedArrays(A,m/2+1, &B[m-(m/2+1)] ,n-(m-(m/2+1)));
            else
                return findMedianSortedArrays(A,1, &B[1] ,n-1);
        }
    }
    
    double mid(int a[],int n)
    {
        if((n&1)==1)
            return a[n/2];
        else
            return (a[n/2-1]+a[n/2])/2.0;
    }
    double mid2(int x, int a[], int n)
    {
        if((n&1)==0)
        {
            if(x>=a[n/2]) return a[n/2];
            else if(x<=a[n/2-1]) return a[n/2-1];
            else
                return x;
        }
        else
        {
            if(n==1) return (a[0]+x)/2.0;
            if(x>=a[n/2+1]) return (a[n/2]+a[n/2+1])/2.0;
            else if(x<=a[n/2-1]) return (a[n/2]+a[n/2-1])/2.0;
            else return (a[n/2]+x)/2.0;
        }
    }
};