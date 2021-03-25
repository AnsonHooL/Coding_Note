//
// Created by lenovo on 2021/3/18.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        left--;right--;

        ListNode* myhead = new ListNode(0);
        myhead->next = head;
        head = myhead;

        ListNode* m;
        ListNode* n;
        stack<ListNode*> mystack;

        for(int i = 0; i < left; i++)
        {
            head = head->next;
        }
        m = head;

        // cout<< m->val << endl;
        for(int i = 0; i <= (right - left +1); i++)
        {
            head = head->next;
            mystack.push(head);
        }
        mystack.pop();
        n = head;
        while(!mystack.empty())
        {
            m->next = mystack.top();
            mystack.pop();
            m = m->next;
        }
        m->next = n;
        return myhead->next;
    }
};

/**反转 m 到 n 结点的链表，用栈就行了*/