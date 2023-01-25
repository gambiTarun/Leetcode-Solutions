class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end());
        vector<vector<int>> res(people.size(),{-1,-1});
        
        for(int i=0;i<people.size();i++){
            int taller = people[i][1];
            int idx=0;
            while(taller>0){
                // cout<<idx<<"D"<<res[idx][0]<<endl;
                taller -= (res[idx][0]==-1 || res[idx][0]>=people[i][0])?1:0;
                idx++;
            }
            // cout<<idx<<":"<<people[i][0]<<","<<people[i][1]<<endl;
            while(res[idx][0]!=-1)
                idx++;
            
            res[idx] = people[i];
        }
            
        return res;
    }
};