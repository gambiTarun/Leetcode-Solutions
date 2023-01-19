class Solution {
public:
    int vis[26] = {0};
    
    string alienOrder(vector<string>& words) {
        map<char,vector<char>> adj;
        for(int i=0;i<words.size()-1;i++){
            string w1 = words[i];
            string w2 = words[i+1];
            int l = min(w1.size(),w2.size());
            // cout<<w1.substr(0,l)<<","<<w2.substr(0,l)<<endl;
            if(w1.substr(0,l)==w2.substr(0,l) && w1.size()>w2.size())
                return "";
            for(int i=0;i<w1.size();i++)
                if(adj.find(w1[i])==adj.end())
                    adj[w1[i]].push_back({});
            for(int i=0;i<w2.size();i++)
                if(adj.find(w2[i])==adj.end())
                    adj[w2[i]].push_back({});
            
            for(int j=0;j<l;j++){
                if(w1[j]!=w2[j]){
                    adj[w1[j]].push_back(w2[j]);
                    break;
                }
            }
        }
        if(words.size()==1){
            for(int i=0;i<words[0].size();i++)
                if(adj.find(words[0][i])==adj.end())
                    adj[words[0][i]].push_back({});
        }
        
        string ans;
        for(auto letter: adj){
            if(isCyclic(adj, letter.first, ans))
                return "";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool isCyclic(map<char,vector<char>> adj, char curr, string &path){
        if(!curr)
            return false;
        if(vis[curr-'a']==1)
            return true;
        if(vis[curr-'a']==0){
            vis[curr-'a']=1;
            for(char next:adj[curr])
                if(isCyclic(adj,next,path))
                    return true;
                path.push_back(curr);
        }
        vis[curr-'a']=2;
        return false;
    }
};