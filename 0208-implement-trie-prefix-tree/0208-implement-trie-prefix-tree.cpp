class Trie {
public:
    class TrieNode{
        public:
        TrieNode *children[26]={};
        bool endOfWord = false;
    };
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();    
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        
        for(char c:word){
            if(!curr->children[c-'a'])
                curr->children[c-'a'] = new TrieNode();
            curr = curr->children[c-'a'];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        
        for(char c:word){
            if(!curr->children[c-'a'])
                return false;
            curr = curr->children[c-'a'];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(char c:prefix){
            if(!curr->children[c-'a'])
                return false;
            curr = curr->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */