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
    bool isPalindrome(ListNode* head) 
    {
        //快慢指针法，快指针走到最后的时候，慢指针是中间位置，慢指针一路走过来把数据push到栈内，快指针为空的时候比较栈内数据和后一半数据是否相等
        ListNode* fast = head;
        ListNode* slow = head;
        if(head == NULL)
            return true;
        std::stack<int> s;
        s.push(head->val);
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            s.push(slow->val);
        }
        if(!fast->next)
        {
            s.pop();
        }
        if(slow)
        {
            while(slow->next)
            {
                slow = slow->next;
                if(slow->val != s.top())
                    return false;
                s.pop();
            }
        }
        else
            return false;
        return true;
    }
};