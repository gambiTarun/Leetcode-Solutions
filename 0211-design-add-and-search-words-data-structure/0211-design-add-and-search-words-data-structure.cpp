class Trie{
    public:
    Trie *chars[26]={};
    bool wordEnd = false;
};

class WordDictionary {
public:
    Trie *root;
    
    WordDictionary() {
        root = new Trie();    
    }
    
    void addWord(string word) {
        Trie* curr = root;
        for(char c:word){
            if(!curr->chars[c-'a'])
                curr->chars[c-'a'] = new Trie();
            curr = curr->chars[c-'a'];
        }
        curr->wordEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(0,word,root);
    }
    
    bool searchHelper(int st, string word, Trie* curr){
        
        for(int i=st;i<word.size();i++){
            
            if(word[i]!='.'){
                if(!curr->chars[word[i]-'a']) return false;
                curr=curr->chars[word[i]-'a'];
            }
            else{
                bool found=false;
                for(auto x:curr->chars){
                    if(x) found |= searchHelper(i+1,word,x);
                    if(found) return true;
                }
                return false;
            }
        }
        
        return curr->wordEnd;
    }
        
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */