class Solution {
public:
    int numberOfSteps(int num) {
        return num? bitset<32>(num).count() + log2(num):0;
    }
};