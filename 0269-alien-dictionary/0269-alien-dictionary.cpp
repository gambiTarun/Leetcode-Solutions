class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,vector<char>> adj;
        for(int i=0;i<words.size()-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            int l = min(w1.size(),w2.size());
            if(w1.substr(0,l)==w2.substr(0,l) && w1.size()>w2.size())
                return "";
            for(int i=0;i<w1.size();i++)
                if(adj.count(w1[i])==0)
                    adj[w1[i]].push_back({});
            for(int i=0;i<w2.size();i++)
                if(adj.count(w2[i])==0)
                    adj[w2[i]].push_back({});
            
            for(int i=0;i<l;i++){
                if(w1[i]!=w2[i]){
                    adj[w1[i]].push_back(w2[i]);
                    break;
                }
            }
        }
        if(words.size()==1){
            for(int i=0;i<words[0].size();i++)
                if(adj.count(words[0][i])==0)
                    adj[words[0][i]].push_back({});
        }
         
        vector<int> vis(26,0);
        string res="";
        for(auto x:adj)
            if(iscyclic(adj, x.first, res, vis))
                return "";
        
        // for(auto x:adj){
        //     cout<<x.first<<":";
        //     for(int i=0;i<x.second.size();i++)
        //         cout<<x.second[i]<<',';
        //     cout<<endl;
        // }
        reverse(begin(res),end(res));
        return res;
    }
    
    bool iscyclic(unordered_map<char,vector<char>> &adj, char c, string &res, vector<int> &vis){
        if(vis[c-'a']==1)
            return true;
        else if(vis[c-'a']==0){
            vis[c-'a']=1;
            for(char n: adj[c]){
                if(adj.count(n) && iscyclic(adj,n,res,vis))
                    return true;
            }
            res+=c;
            vis[c-'a']=2;
        }
        return false;
    }
};