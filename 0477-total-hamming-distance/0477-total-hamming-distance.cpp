class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res=0,c;
        for(int i=0;i<32;i++){
            c=0;
            for(auto n:nums){
                c += (n>>i)&1;
            }
            res+=(nums.size()-c)*c;
        }
        return res;
    }
};