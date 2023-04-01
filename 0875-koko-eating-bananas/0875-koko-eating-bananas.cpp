class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h==piles.size())
            return *max_element(begin(piles),end(piles));
        
        int l=1,r=*max_element(begin(piles),end(piles)),m;
        while(l<=r){
            m = l+(r-l)/2;
            long hrsreq = 0;
            for(int i=0;i<piles.size();i++)
                hrsreq += piles[i]/m + (piles[i] % m != 0);
            if(hrsreq>h)
                l=m+1;
            else
                r=m-1;
        }
        return l;
    }
};