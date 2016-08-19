// 157
// Read N Characters Given Read4
// https://leetcode.com//problems/read-n-characters-given-read4/
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char aux_buf[4];
        int left=n,num=0;
        do{
            num =read4(aux_buf);
            int m= min(num,left);
            for(int i=0;i<m;++i)
                buf[i]=aux_buf[i];
            left-=m;
            buf+=m;
        }while(num==4 && left>0);
        return n-left;
    }
};