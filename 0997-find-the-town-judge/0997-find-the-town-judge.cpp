class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1&&trust.size()==0)
            return 1;
        vector<int> ind(n+1,0);
        for(auto t:trust){
            ind[t[0]]--;
            ind[t[1]]++;
        }
        auto it = max_element(ind.begin(),ind.end());
        return *it==n-1?it-ind.begin():-1;
    }
};