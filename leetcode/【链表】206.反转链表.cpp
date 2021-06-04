//
// Created by lenovo on 2021/5/24.
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
    ListNode* re;

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            re = head;
            return head;
        }
        reverse(head)->next = NULL;
        return re;
    }

    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) {
            re = head;
            return head;
        }
        reverse(head->next)->next = head;
        return head;
    }
};

class Solution {
public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);
    }
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    }

};