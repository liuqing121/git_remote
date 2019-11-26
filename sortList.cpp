/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* sortList(ListNode* head) 
    {
        //归并排序，剪切链表后排序合并
        int length = 0;
        //获得链表长度
        ListNode* tmp = head;
        while(tmp)
        {
            length++;
            tmp = tmp->next;
        }
        ListNode phead = ListNode(0);  //加一个链表头
        phead.next = head;
        for(int size = 1; size < length; size <<= 1)
        {
            ListNode* cur = phead.next;
            ListNode* tail = &phead;
            while(cur)
            {
                ListNode* left = cur;
                ListNode* right = cutlist(left, size);
                cur = cutlist(right,size);
                tail->next = mergelist(left, right);
                while(tail->next)
                {
                    tail = tail->next;
                }
            }
        }
        return phead.next;
    }
    ListNode* cutlist(ListNode* node, int size)
    {
        while(--size && node)
        {
            node = node->next;
        }
        if(!node)
            return NULL;
        ListNode* nextnode = node->next;
        node->next = NULL;
        return nextnode;
    }
    ListNode* mergelist(ListNode* list1, ListNode* list2)
    {
        ListNode* newhead = new ListNode(0);
        ListNode* p = newhead;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                p->next = list1;
                p = list1;
                list1 = list1->next;
            }
            else
            {
                p->next = list2;
                p = list2;
                list2 = list2->next;
            }
        }
        p->next = list1? list1:list2;
        return newhead->next;
    }
};