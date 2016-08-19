// 165
// Compare Version Numbers
// https://leetcode.com//problems/compare-version-numbers/
class Solution {
public:
     int compareVersion(string version1, string version2) {
        for(size_t i=0,l=0;;){
            size_t j=version1.find('.', i), m=version2.find('.',l);
            int a = i<string::npos? stoi(version1.substr(i,j-i)):0, b= l<string::npos?stoi(version2.substr(l,m-l)):0;
            if(a>b) return 1;
            else if(a<b) return -1;
            else{
                if(j==string::npos && m==string::npos) return 0;
                i= j==string::npos? j:j+1;
                l= m==string::npos? m:m+1;
            }
        }
    }
};