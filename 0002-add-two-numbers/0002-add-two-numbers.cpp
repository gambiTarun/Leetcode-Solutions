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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode();
        ListNode* node = root;
        int c=0,tmp=0;
        while(l1 || l2 || c){
            tmp = (l1?l1->val:0) + (l2?l2->val:0) + c;
            c = tmp/10;
            node->next = new ListNode(tmp%10);
            node = node->next;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        
        return root->next;
    }
};