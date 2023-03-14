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
        stack<int> s1,s2;
        while(l1 || l2){
            if(l1) s1.push(l1->val);
            if(l2) s2.push(l2->val);
            l1 = l1?l1->next:l1;
            l2 = l2?l2->next:l2;
        }
        
        ListNode* node = new ListNode();
        int c=0,tmp;
        while(!s1.empty() || !s2.empty() || c){
            tmp = (s1.empty()?0:s1.top()) + (s2.empty()?0:s2.top()) + c;           
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
            c = tmp/10;
            node->val = tmp%10;
            node = new ListNode(0,node);
        }
        return node->next;
    }
};