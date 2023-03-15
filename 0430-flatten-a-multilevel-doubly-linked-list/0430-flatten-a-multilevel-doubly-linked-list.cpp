/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *last=NULL;
    Node* flatten(Node* head) {
        if(!head)
            return NULL;
        
        Node *root = head;
        last = head;
        
        if(head->child){
            Node *tmp = head->next;
            // last = head;
            head->next = flatten(head->child);
            head->child = NULL;
            if(tmp) tmp->prev = last;
            last->next = tmp;
            head->next->prev = head;

            head = last;
        }
        
        flatten(head->next);
            
        return root;
    }
};