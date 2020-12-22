//
// Created by lenovo on 2020/9/20.
//


/******合并有序链表 注意边界情况的考虑******/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tmp  = NULL;
        if(l1==NULL && l2==NULL) return head;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1 && l2) {
            if (l1->val < l2->val) {
                head = l1;
                l1 = l1->next;
            } else {
                head = l2;
                l2 = l2->next;
            }
            tmp = head;
            while (l1 && l2)
            {
                if (l1->val < l2->val) {
                    tmp->next =l1;
                    l1 = l1->next;
                } else {
                    tmp->next = l2;
                    l2 = l2->next;
                }
                tmp=tmp->next;
            }
        }
        while (l1)
        {
            tmp->next = l1;
            l1 = l1->next;
            tmp=tmp->next;
        }
        while (l2)
        {
            tmp->next = l2;
            l2 = l2->next;
            tmp=tmp->next;
        }
        tmp->next=NULL;

        return  head;
    }
};

///妙啊，头插法 + 递归！！！！！！！！！
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }

    }
};
