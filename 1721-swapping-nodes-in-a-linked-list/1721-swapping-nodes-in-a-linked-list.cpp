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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p1=head,*p2=head;
        for(int i=0;i<k;i++)
            p2=p2->next;
        while(p2){
            p1=p1->next;
            p2=p2->next;
        }
        p2=head;
        for(int i=0;i<k-1;i++)
            p2=p2->next;
        // cout<<p1->val<<","<<p2->val<<endl;
        swap(p1->val,p2->val);
        return head;
    }
};