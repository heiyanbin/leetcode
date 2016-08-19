// 166
// Fraction to Recurring Decimal
// https://leetcode.com//problems/fraction-to-recurring-decimal/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator){
        long long r =numerator, d =denominator;
        if(r==0) return "0";
        string res;
        vector<int> v;
        if((r>>31) ^ (d>>31)) res.push_back('-');
        r=abs(r);
        d=abs(d);
        long long x=r/d;
        res.append(to_string(x));
        r = r % d;
        if(r==0) return res;
        res.push_back('.');
        while(true) {
            r *=10;
            x = r/d;
            r %=d;
            if(r==0){
                res.append(to_string(x));
                return res;
            }
            else {
                int i = find(v.rbegin(),v.rend(),r)-v.rbegin()+1;
                if(i>0 && i<=v.size() && res[res.size()-i]-'0'==x){
                    res.insert(res.end()-i,'(');
                    res.push_back(')');
                    return res;
                }
                else
                    res.append(to_string(x));
            }
            v.push_back(r);
        }
    }
};