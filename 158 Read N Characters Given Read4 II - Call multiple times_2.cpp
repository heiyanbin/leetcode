// 158
// Read N Characters Given Read4 II - Call multiple times
// https://leetcode.com//problems/read-n-characters-given-read4-ii-call-multiple-times/
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
        int toRead =n;
        int m = min(remain,toRead);
        memcpy(buf,aux_buf+remain_start,m);
        buf+=m;
        toRead-=m;
        remain_start+=m;
        remain-=m;
        if(toRead ==0)  return m;
        while(toRead)
        {
            int x = read4(aux_buf);
            m = min(x,toRead);
            memcpy(buf,aux_buf,m);
            buf+=m;
            toRead-=m;
            if(m<x)
            {
                remain=x-m;
                remain_start = m;
            }
            if(x<4) return n-toRead;
        }
        return n;
    }
    Solution():remain(0),remain_start(0){}
private:
    int remain;
    int remain_start;
    char  aux_buf[4];
};