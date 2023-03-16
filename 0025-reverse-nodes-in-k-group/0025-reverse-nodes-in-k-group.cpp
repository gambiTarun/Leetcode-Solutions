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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
            return head;
        
        ListNode *res = new ListNode();
        ListNode *p1 = head, *p2 = head, *prev=res;
        int i=0;
        
        while(p2){
            for(i=0;i<k && p2;i++)
                p2 = p2->next;
            if(i!=k) break;
            p1 = rev(p1,k,prev);
            p1->next = p2;
            prev = p1;
            p1 = p1->next;
        }
        return res->next;
    }
    
    ListNode* rev(ListNode* node, int n, ListNode* linker){
        ListNode *prev=NULL,*curr=node,*next=node->next;
        
        while(n--){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next?next->next:next;
        }
        linker->next=prev;
        
        return node;
    }
};