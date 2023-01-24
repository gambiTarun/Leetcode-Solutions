class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int n = *min_element(nums.begin(), nums.end()),res=0;
        while(n>0){
            res+=n%10;
            n/=10;
        }
        return res%2?0:1;
    }
};