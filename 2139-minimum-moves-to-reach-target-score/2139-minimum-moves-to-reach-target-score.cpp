class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int c=0;
        while(maxDoubles && target){
            if(target%2==0){
                target/=2;
                maxDoubles--;
            }
            else
                target--;
            c++;
        }
        return target+c-1;
    }
};