//
// Created by lenovo on 2020/12/2.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthb = 0;
        int lengtha = 0;
        ListNode* p = headA;
        while(p)
        {
            p = p->next;
            lengtha++;
        }
        p = headB;
        while(p)
        {
            p = p->next;
            lengthb++;
        }
        while (lengtha > lengthb)
        {
            headA = headA->next;
            lengtha--;
        }
        while (lengthb > lengtha)
        {
            headB = headB->next;
            lengthb--;
        }
        while (headA && headB)
        {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;

    }
};

/**
 * 链表A、B的第一个公共阶段
 *
 *问题是空间要O（1）,因此耗时可以多一些
 *
 * /