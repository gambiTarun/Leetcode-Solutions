class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string,string> mp;
        mp[regions[0][0]]="";
        for(auto r:regions){
            for(int i=0;i<r.size();i++){
                mp.insert({r[i],r[0]});
            }
        }
        
        unordered_set<string> st;
        string s=region1;
        while(s!=""){
            st.insert(s);
            s = mp[s];
        }
        
        s = region2;
        while(s!=""){
            if(st.find(s)!=st.end())
                return s;
            s = mp[s];
        }
        return regions[0][0];
    }
};