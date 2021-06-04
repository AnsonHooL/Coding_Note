//
// Created by lenovo on 2021/6/3.
//

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head;
        ListNode* cur = &head;
        auto greater = [](ListNode* lhs, ListNode* rhs) -> auto {
            return lhs->val > rhs->val;
        };

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