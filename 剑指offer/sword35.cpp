//
// Created by lenovo on 2020/9/25.
//

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* myhead = new Node(head->val);
        Node* tmp    = myhead;
        Node* A      = head;
        while(tmp!=NULL)
        {
            mymap.insert(pair<Node*,Node*>(head,tmp));
            if(head->next)
            {
                Node* a = new Node(head->next->val);
                tmp->next = a;
            }
            else
            {
                tmp->next = NULL;
            }
            tmp  = tmp->next;
            head = head->next;
        }
        tmp  = myhead;
        head = A;
        while(tmp!=NULL)
        {
            if(head->random)
            {
                auto iter   = mymap.find(head->random);
                tmp->random = iter->second;
            }
            tmp  = tmp->next;
            head = head->next;
        }
        return myhead;

    }
    unordered_map<Node*,Node*> mymap; // OLD -> NEW

};