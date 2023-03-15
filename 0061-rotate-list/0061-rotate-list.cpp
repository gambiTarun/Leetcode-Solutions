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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        
        ListNode *p1=head,*p2=head;
        int n=0;
        while(p1 && ++n)
            p1 = p1->next;
        
        k = k%n;
        while(k--)
            p2 = p2->next;
        
        p1 = head;
        while(p2->next){
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = head;
        head = p1->next;
        p1->next = NULL;
            
        return head;
    }
};