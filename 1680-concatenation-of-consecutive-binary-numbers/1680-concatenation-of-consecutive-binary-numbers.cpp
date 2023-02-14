class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9+7;
        long res=0,l=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0)
                l++;
            res = ((res<<l)|i) % MOD;
        }
        return res;
    }
};