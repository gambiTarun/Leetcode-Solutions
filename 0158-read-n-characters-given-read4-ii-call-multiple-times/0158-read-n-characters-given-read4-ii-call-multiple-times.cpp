/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char tmp[4];
    int start=0,end=0;
    
    int read(char *buf, int n) {
        int re=0,act=0,i=0;
        cout<<n<<":"<<start<<","<<end<<endl;
        
        if(start==0)
            end = read4(tmp);
        
        for(int j=start;j<end && i<n;j++){
            buf[i++] = tmp[j];
            start=j;
        }
        while(i<n && (end=read4(tmp))==4){
            for(int j=0;j<end && i<n;j++){
                buf[i++] = tmp[j];
                start=j;
            }
        }
        if(end<4){
            for(int j=0;j<end && i<n;j++){
                buf[i++] = tmp[j];
                start=j;
            }
        }
        cout<<i<<endl;
        // cout<<re<<endl;
        start = (start+1)%4;
        return i;
    }
};