/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(!head)
            return vector<ListNode*>(k);
        vector<ListNode*> res = {head};
        int n=0;
        ListNode *node=head, *prev;
        while(node && ++n)
            node = node->next;
        node = head;
        int div=n/k,div1=n%k;
        while(--k){
            for(int i=0;i<div;i++){
                prev = node;
                node = node->next;
            }
            if(div1-->0){
                prev = node;
                node=node->next;
            }
            prev->next = NULL;
            res.push_back(node);
        }
        
        return res;
    }
};