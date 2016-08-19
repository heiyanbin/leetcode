// 166
// Fraction to Recurring Decimal
// https://leetcode.com//problems/fraction-to-recurring-decimal/
class Solution {
public:
    string fractionToDecimal(int a, int b){
        if(a==0) return "0";
        long long r =a, d =b;
        string res;
        unordered_map<int,int> m;
        if(r<0 ^ d<0) res.push_back('-');
        r=abs(r), d=abs(d);
        res.append(to_string(r/d));
        if((r%d)==0) return res;
        res.push_back('.');
        for(r %=d;r;r%=d) {
            if(m.find(r)!=m.end()){
                res.insert(m[r],"(");
                res.push_back(')');
                break;
            }
            m[r]= res.size();
            r *=10;
            res.append(to_string(r/d));
        }
        return res;
    }
};