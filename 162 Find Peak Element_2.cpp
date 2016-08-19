// 162
// Find Peak Element
// https://leetcode.com//problems/find-peak-element/
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int L=0, R=num.size()-1;
        while(L<R)
        {
            int mid= L+(R-L)/2;
            if(num[mid]>num[mid+1])
                R=mid;
            else
                L=mid+1;
        }
        return L;
    }
};