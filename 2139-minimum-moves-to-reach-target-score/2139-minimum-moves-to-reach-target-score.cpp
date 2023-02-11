class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int c=0;
        while(maxDoubles && target>1){
            c += 1+target%2;
            target>>=1;
            maxDoubles--;
        }
        return target+c-1;
    }
};