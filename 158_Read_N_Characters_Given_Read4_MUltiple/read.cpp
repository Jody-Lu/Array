// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    Solution(): buffCnt(0), buffPtr(0) {}
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int ptr = 0;
        while(ptr < n) {
            if(buffPtr == 0) {
                buffCnt = read4(buff);
            }

            // no chars to read
            if(buffCnt == 0) { break; }

            // write the chars from buff to buf
            while(ptr < n && buffPtr < buffCnt) {
                buf[ptr++] = buff[buffPtr++];
            }
            // read all, reset
            if(buffPtr == buffCnt) { buffPtr = 0; }
        }

        return ptr;
    }

private:
    int buffCnt;
    int buffPtr;
    char buff[5];
};