//
// Created by lenovo on 2021/6/2.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head;
        ListNode* cur = &head;
        auto greater = [](ListNode* lhs, ListNode* rhs) -> auto {
            return lhs->val > rhs->val;
        };
        ///看看这个优先级队列的生命，decltype(greater)这是类型，然后传参
        priority_queue<ListNode*,vector<ListNode*>, decltype(greater)> Q(greater);

        for(int i = 0; i < lists.size(); i++){

            if(lists[i]) Q.push(lists[i]);

        }
        while (!Q.empty()){
            ListNode* node = Q.top();
            Q.pop();
            if(node->next) Q.push(node->next);
            cur->next = node;
            cur = node;
        }
        return head.next;
    }
};


/**
 * 给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

 

示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：

输入：lists = []
输出：[]
示例 3：

输入：lists = [[]]
输出：[]

思路：就是一个优先级队列就完事了！


 * */