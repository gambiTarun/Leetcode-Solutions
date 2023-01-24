class Solution {
public:
    int alternateDigitSum(int n) {
        int res=0 ,len=0, tmp;
        while(n>0){
            tmp = n%10;
            n/=10;
            len++;
            res += tmp*(len%2?-1:1);
        }
        return len%2?res*-1:res;
    }
};