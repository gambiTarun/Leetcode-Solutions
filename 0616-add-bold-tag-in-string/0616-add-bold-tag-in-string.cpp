class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        vector<int> b(s.size(),0);
        for(string x:words){
            int index=0;
            while(index<s.size()){
                int i=s.find(x, index);
                index++;
                for(int j=i;j<x.size()+i;j++)
                    b[j]=1;
            }
        }
        
        string res="";
        for(int i=0;i<b.size();i++){
            if(b[i]==0){
                if(i!=0 && b[i-1]==1){
                    res.push_back('<');
                    res.push_back('/');
                    res.push_back('b');
                    res.push_back('>');
                }
                res.push_back(s[i]);
            }
            else{
                if(i==0 || b[i-1]==0){
                    res.push_back('<');
                    res.push_back('b');
                    res.push_back('>');
                }
                res.push_back(s[i]);
            }
                          
        }
        
        if(b[b.size()-1]==1){
            res.push_back('<');
            res.push_back('/');
            res.push_back('b');
            res.push_back('>');
        }
        return res;
    }
};