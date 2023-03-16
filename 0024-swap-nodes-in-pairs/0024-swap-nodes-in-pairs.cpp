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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *p1=head,*p2=head->next, *prev=NULL;
        ListNode *res = p2;
        while(p1&&p2){
            p1->next = p2->next;
            p2->next = p1;
            if(prev) prev->next = p2;
            prev = p1;
            p1 = p1->next;
            p2 = p1?p1->next:NULL;
        }
        return res;
    }
};