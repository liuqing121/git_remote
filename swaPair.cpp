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
    ListNode* swapPairs(ListNode* head) 
    {
        //递归改指针指向
        if(!head)
            return NULL;
        ListNode* tail = head;
        ListNode* tmpnext = NULL;
        if(head->next)    
        {
            tmpnext = head->next->next;
            head = head->next;
            head->next = tail;
        }
        tail->next = swapPairs(tmpnext);
        return head;
    }
};