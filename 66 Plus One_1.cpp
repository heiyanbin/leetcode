// 66
// Plus One
// https://leetcode.com//problems/plus-one/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry =1;
        for(auto it=digits.rbegin();it!=digits.rend() && carry>0;it++)
        {
            *it=*it+carry;
            carry=*it/10;
            *it=*it%10;
        }
        if(carry>0)
            digits.insert(digits.begin(),1);
        return digits;
    }
};