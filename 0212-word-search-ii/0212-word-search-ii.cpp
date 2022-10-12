class Trie{
    public:
    Trie* child[26] = {};
    bool endWord = false;
    string word = "";
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        vector<string> ans;
        for(string s:words)
            addWord(root,s);
        
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                findWord(board,i,j,root,ans);
            }
        }

        return ans;
    }
    
    void addWord(Trie* root, string s){
        Trie *curr = root;
        
        for(char c:s){
            if(!curr->child[c-'a'])
                curr->child[c-'a'] = new Trie();
            curr=curr->child[c-'a'];
        }
        curr->endWord = true;
        curr->word = s;
    }
    
    void findWord(vector<vector<char>> &board, int i, int j, Trie* node, vector<string> &ans){
        
        if(i>=board.size() || i<0 || j>=board[0].size() || j<0) return;
        
        char c = board[i][j];
        
        if(c=='*' || !node->child[c-'a'])
            return;
        
        node = node->child[c-'a'];
        
        board[i][j] = '*';
        
        if(node->endWord){
            ans.push_back(node->word);
            node->endWord=false;
        }
        
        findWord(board, i+1, j, node, ans);
        findWord(board, i-1, j, node, ans);
        findWord(board, i, j+1, node, ans);
        findWord(board, i, j-1, node, ans);
        
        board[i][j] = c;

    }
};