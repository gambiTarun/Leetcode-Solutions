class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long bm=0;
        for(auto n:nums)
            bm^=n;
        int a=0,diff=bm&(-bm);
        for(auto n:nums)
            if(diff&n)
                a^=n;
    
        return {a,(int)bm^a};
    }
};