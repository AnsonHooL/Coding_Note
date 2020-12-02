//
// Created by lenovo on 2020/9/19.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* tmp = head;
        ListNode* re  = head;
        for(int i=0;i<k-1;i++)
        {
            if(tmp ==NULL)
                return NULL;
            tmp=tmp->next;
        }
        while(tmp)
        {
            tmp=tmp->next;
            re =re->next;
        }
        return re;
    }
};