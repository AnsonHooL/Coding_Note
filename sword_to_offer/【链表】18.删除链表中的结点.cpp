//
// Created by lenovo on 2020/9/18.
//

/*****删除 插入 节点*****/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode myhead(0);
        myhead.next = head;
        ListNode* tmp = &myhead;
        while(tmp!=NULL && tmp->next!=NULL)
        {
            if(tmp->next->val == val)
            {
                tmp->next = tmp->next->next;
            }
            tmp=tmp->next;
        }
        return myhead.next;

    }
};

///有意思的是，增加一个头节点