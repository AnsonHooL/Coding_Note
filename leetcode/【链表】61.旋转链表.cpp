//
// Created by lenovo on 2021/3/28.
//

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL) return head;

        int size = 1;
        ListNode* p = head;
        while(p->next)
        {
            size++;
            p = p->next;
        }
        ListNode* tail = p;
        tail->next = head; ///首尾相连

        k = k % size;

        int runlen = size - k - 1;

        p = head;
        for(int i = 0; i < runlen; i++)
        {
            p = p->next;
        }
        ListNode* newhead = p->next; ///在这里断开
        p->next = NULL;

        return newhead;
    }
};

/**
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 *
 * 先首尾相连，再选取新的头节点
 *
 *
 *
 * */