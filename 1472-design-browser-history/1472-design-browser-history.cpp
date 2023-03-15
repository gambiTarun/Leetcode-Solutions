class Node{
public:
    string url;
    Node *prev, *next;
    Node(string u, Node* p, Node* n)
        :url(u), prev(p), next(n)
    {    
    }
};
class BrowserHistory {
public:
    Node* curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage, NULL, NULL);
    }
    
    void visit(string url) {
        // if(curr->next) delFor(curr->next);
        curr->next = new Node(url,curr,NULL);
        curr = curr->next;
    }
    
    string back(int steps) {
        while(steps-- && curr->prev)
            curr = curr->prev;
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps-- && curr->next)
            curr = curr->next;
        return curr->url;
    }

private:
    void delFor(Node* n){
        Node *tmp=n;
        while(n){
            n = n->next;
            delete tmp;
            tmp=n;
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */