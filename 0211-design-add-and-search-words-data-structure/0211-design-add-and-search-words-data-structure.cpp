class Trie{
public:
    Trie *chars[26];
    bool end = false;
};
class WordDictionary {
public:
    Trie *root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *node = root;
        
        for(char c:word){
            if(!node->chars[c-'a'])
                node->chars[c-'a'] = new Trie();
            node = node->chars[c-'a'];
        }
        node->end=true;
    }
    
    bool search(string word) {
        return searchHelper(word, root);
    }
    bool searchHelper(string sub, Trie *node){
        // cout<<sub<<endl;
        for(int j=0;j<sub.size();j++){
            if(sub[j]=='.'){
                bool found=false;
                for(int i=0;i<26;i++){
                    if(!found && node->chars[i])
                        found |= searchHelper(sub.substr(j+1), node->chars[i]);
                }
                return found;
            }
            else{
                if(!node->chars[sub[j] - 'a'])
                    return false;
                node = node->chars[sub[j] - 'a'];
            }
        }
        return node->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */