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
        //����ָ�뷨����ָ���ߵ�����ʱ����ָ�����м�λ�ã���ָ��һ·�߹���������push��ջ�ڣ���ָ��Ϊ�յ�ʱ��Ƚ�ջ�����ݺͺ�һ�������Ƿ����
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