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
        int numRead =0;
        for(bool eof=false; numRead<n && !eof;) {
            if(len==0){
                len = read4(aux_buf);
                eof = len<4;
            }
            int m = min(len,n-numRead);
            memcpy(buf+numRead,aux_buf+start,m);
            numRead +=m;
            len-=m;
            start = (start+m)%4;
        }
        return numRead;
    }
    Solution():len(0),start(0){}
private:
    int len;
    int start;
    char  aux_buf[4];
};