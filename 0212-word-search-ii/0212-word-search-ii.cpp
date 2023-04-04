class Trie{
public:
    Trie *chars[26];
    bool end=false;
};
class Solution {
public:
    Trie *root = new Trie();
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string w: words)
            addWord(w);
        
        vector<string> res;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                string tmp="";
                dfs(board,i,j,res,root,tmp);
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<char>> &b, int i, int j, vector<string> &res, Trie *node, string &tmp){
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size() || b[i][j]=='_')
            return;
        
        char c = b[i][j];
        if(!node->chars[c-'a'])
            return;

        node = node->chars[c-'a'];
        tmp+=c;
        
        if(node->end){
            res.push_back(tmp);
            node->end = false;
        }
        
        b[i][j] = '_';
        
        dfs(b,i+1,j,res,node,tmp);
        dfs(b,i,j+1,res,node,tmp);
        dfs(b,i-1,j,res,node,tmp);
        dfs(b,i,j-1,res,node,tmp);
        
        b[i][j]=c;
        
        tmp.pop_back();
        
    }
    
    void addWord(string w){
        Trie *node = root;
        
        for(char c:w){
            if(!node->chars[c-'a'])
                node->chars[c-'a'] = new Trie();
            node = node->chars[c-'a'];
        }
        node->end = true;
    }
};