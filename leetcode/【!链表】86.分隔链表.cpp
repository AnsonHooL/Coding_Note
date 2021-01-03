//
// Created by lenovo on 2021/1/3.
//

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* big   = new ListNode(0);
        ListNode* shead = small;
        ListNode* bhead = big;
        while(head)
        {
            if(head->val < x)
            {
                small->next = head;
                small = small->next;
                head = head->next;
            } else
            {
                big->next = head;
                big = big->next;
                head = head->next;
            }
        }
        big->next = NULL; ///!!!!要置NULL
        small->next = bhead->next;

        return shead->next;

    }
};

/**
 *
 * 给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

 

示例：

输入：head = 1->4->3->2->5->2, x = 3
输出：1->2->2->4->3->5

*/