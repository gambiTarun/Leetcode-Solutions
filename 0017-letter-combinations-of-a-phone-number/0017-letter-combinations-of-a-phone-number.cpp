class Solution {
public:
    unordered_map<char,string> mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string tmp = "";
        if(digits.size()==0)
            return res;
        dfs(digits,res,0,tmp);
        return res;
    }
    void dfs(string &d, vector<string> &arr, int spos, string &tmp){
        if(tmp.size()==d.size()){
            arr.push_back(tmp);
            return;
        }
        
        for(char c:mp[d[spos]]){
            tmp+=c;
            dfs(d,arr,spos+1,tmp);
            tmp.pop_back();
        }
    }
};