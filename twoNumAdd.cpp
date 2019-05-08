/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(!l1 && !l2)
            return NULL;
        
        if(!l1)
            return l2;
        else if(!l2)
            return l1;
        
        ListNode* l3 = new ListNode((l1->val + l2->val)%10);
        if((l1->val + l2->val) >= 10)
            l3->next = addTwoNumbers(addTwoNumbers(l1->next,l2->next),new ListNode(1));
        else
            l3->next = addTwoNumbers(l1->next,l2->next);
        return l3;
    }

};