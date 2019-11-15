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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        //遍历到尾部，若尾节点相同则相交，之后让长的链表先走差值步
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode* curA = headA;
        ListNode* curB = headB;
        int sizeA = 1;
        int sizeB = 1;
        while(curA->next)
        {
            curA = curA->next;
            sizeA++;
        }
        while(curB->next)
        {
            curB = curB->next;
            sizeB++;
        }
        if(curA == curB)  //相交
        {
            int subsize = 0;
            if(sizeA > sizeB)
            {
                subsize = sizeA-sizeB;
                ListNode* tmpA = headA;
                ListNode* tmpB = headB;
                while(subsize--)
                {
                    tmpA = tmpA->next;
                }
                while(tmpA != NULL && tmpB !=NULL)
                {
                    if(tmpA == tmpB)
                    {
                        return tmpA;
                    }
                    tmpA = tmpA->next;
                    tmpB = tmpB->next;

                }
            }
            else if(sizeA < sizeB)
            {
                subsize= sizeB-sizeA;
                ListNode* tmpA = headA;
                ListNode* tmpB = headB;
                while(subsize--)
                {
                    tmpB = tmpB->next;
                }
                while(tmpA != NULL && tmpB !=NULL)
                {
                    if(tmpA == tmpB)
                    {
                        return tmpA;
                    }
                    tmpA = tmpA->next;
                    tmpB = tmpB->next;

                }
            }
            else
            {
                ListNode* tmpA = headA;
                ListNode* tmpB = headB;
                while(tmpA != NULL && tmpB !=NULL)
                {
                    if(tmpA == tmpB)
                    {
                        return tmpA;
                    }
                    tmpA = tmpA->next;
                    tmpB = tmpB->next;

                }
            }
        }
        return NULL;
    }
};