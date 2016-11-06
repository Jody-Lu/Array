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
        int res = 0, remain = n;
        while(n > 0) {
            int numRead = min(read4(buf), remain);
            res += numRead;
            buf += numRead;
            if(numRead < 4) { break; }
            remain -= numRead;
        }

        return res;
    }
};