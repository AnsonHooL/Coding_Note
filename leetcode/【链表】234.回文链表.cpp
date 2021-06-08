//
// Created by lenovo on 2021/6/7.
//


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> S;
        auto p = head;
        while(p){
            S.push(p->val);
            p = p->next;
        }
        while(head){
            if(head->val != S.top()) return false;
            else{
                head = head->next;
                S.pop();
            }
        }
        return true;
    }
};

/**
 * 请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true


 思路：
 要求时间复杂度O（n），空间O（1）
 先通过快慢指针定位到中间结点，
 然后reverse后半段的结点，再逐一比较就行。不用栈不用递归
 *
 * */