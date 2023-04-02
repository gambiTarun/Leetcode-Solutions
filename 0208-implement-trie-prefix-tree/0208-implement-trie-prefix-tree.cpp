class Node{
public:
    Node *chars[26];
    bool end=false;
};
class Trie {
public:
    Node *root = new Node();
    Trie() {
        
    }
    
    void insert(string word) {
        Node *node = root;
        
        for(char c:word){
            if(!node->chars[c-'a'])
                node->chars[c-'a'] = new Node();
            node = node->chars[c-'a'];
        }
        node->end=true;
    }
    
    bool search(string word) {
        Node *node = root;
        
        for(char c:word){
            if(!node->chars[c-'a'])
                return false;
            node = node->chars[c-'a'];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        
        for(char c:prefix){
            if(!node->chars[c-'a'])
                return false;
            node = node->chars[c-'a'];
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