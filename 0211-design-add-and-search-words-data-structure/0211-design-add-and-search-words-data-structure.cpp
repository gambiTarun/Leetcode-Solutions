class Trie{
public:
    Trie *child[26]={};
    bool wordend = false;
};
class WordDictionary {
public:
    Trie *root;

    WordDictionary() {
        root = new Trie();    
    }
    
    void addWord(string word) {
        Trie *node=root;
        for(char c:word){
            if(!node->child[c-'a'])
                node->child[c-'a'] = new Trie();
            node = node->child[c-'a'];
        }
        node->wordend=true;
    }
    
    bool search(string word) {
        Trie *node=root;
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                bool found=false;
                for(int j=0;j<26;j++){
                    if(node->child[j]){
                        word[i] = j+'a';
                        found |= search(word);
                    }
                }
                return found;
            }
            else {
                if(!node->child[word[i]-'a'])
                    return false;
                node = node->child[word[i]-'a'];
            }
        }
        return node->wordend;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */