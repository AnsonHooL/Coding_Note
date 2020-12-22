//
// Created by lenovo on 2020/9/19.
//
/*****反转链表***/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* myhead = NULL;
        while(head)
        {
            ListNode* tmp = head;
            head = head->next;
            tmp->next=myhead;
            myhead=tmp;
        }
        return myhead;
    }
};