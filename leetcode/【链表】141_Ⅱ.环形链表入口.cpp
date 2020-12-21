//
// Created by lenovo on 2020/12/21.
//

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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* fast = head; fast = fast->next; fast = fast->next;
        ListNode* slow = head; slow = slow->next;
        while(fast != slow && fast && slow)
        {
            if(fast)
                fast = fast->next;
            if(fast)
                fast = fast->next;
            if(slow)
                slow = slow->next;
        }
        if(!(fast == slow && fast))  return NULL;
        while(head != slow)
        {
            head = head->next;
            slow = slow->next;
        }
        return slow;

    }


};

/***
 *给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：

你是否可以使用 O(1) 空间解决此题？
 

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。


 思路
 1.链表的head到环入口长度是 a ， 环自身的长度是b
 2. f = 2s 快指针是慢指针的两倍
 3. f - s = n*b  ， s = n*b快指针比慢指针多走了nb
 4. a + nb = 环的入口
 5. head走a步 ，slow 走a步，能在环形入口相遇
 *
 *
 *
 * /