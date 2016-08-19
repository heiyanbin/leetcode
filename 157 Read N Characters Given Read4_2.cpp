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
        return read(buf,n,aux_buf);
    }
    int read(char *buf, int n, char*aux_buf)
    {
        if(n<=0) return 0;
        int num = read4(aux_buf);
        for(int i=0;i<min(num,n);++i)
            buf[i]=aux_buf[i];
        if(n<=num||num<4) return min(num,n);
        return 4 + read(buf+4,n-4,aux_buf);
    }
};