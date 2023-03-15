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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return head;
        ListNode *odd = head, *even=head->next;
        ListNode *oh = odd, *eh=even;
        head = even->next;
        while(head && head->next){
            odd->next = head;
            even->next = head->next;
            head = head->next->next;
            odd = odd->next;
            even = even->next;
        }
        if(head){
            odd->next = head;
            odd = odd->next;
        }
        even->next = NULL;
        odd->next = eh;
        return oh;
    }
};