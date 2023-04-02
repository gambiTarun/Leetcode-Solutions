class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string com = "";
        for(int i=0;;i++){
            com += strs[0][i];
            for(string s:strs){
                if(i>=s.size() || com[i]!=s[i]){
                    com.pop_back();
                    return com;
                }
            }
        }
        return com;
    }
};