// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    char *sb = new char[4];
    int end = 4, ptr = end;
    int read(char *buf, int n) {
        int i = 0, offset = 0;
        if(ptr < end){
            offset = min(n, end - ptr);
            memcpy(buf, sb + ptr, offset);
            i += offset, ptr += offset;
        }
        while(i < n && end == 4){
            ptr = 0;
            end = read4(sb);
            memcpy(buf + i, sb, end);
            offset = min(n - i, end);
            i += offset, ptr += offset;
        }
        return i;
    }
};
