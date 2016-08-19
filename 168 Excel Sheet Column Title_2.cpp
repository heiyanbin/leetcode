// 168
// Excel Sheet Column Title
// https://leetcode.com//problems/excel-sheet-column-title/
class Solution {
public:
    string convertToTitle(int n) {
        if(n<=26) return string(1,'A'+ n-1);
        if(n%26==0) return convertToTitle((n-1)/26)+"Z";
        return convertToTitle(n/26) + convertToTitle(n%26);
    }
};