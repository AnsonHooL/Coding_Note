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

///请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
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


///思路保存旧结点到新结点的映射，这样就能搞了，但是空间复杂度O（n）
///还可以原地复制，新链表逐个插入旧链表中，然后复制完，再解耦
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        Node* myhead = head;
        while (head)
        {
            Node* p = new Node(head->val);
            p->next = head->next;
            head->next = p;
            head = p->next;
        }
        head = myhead;
        while (head)
        {
            Node* tmp = head->next;
            if(head->random) tmp->random = head->random->next;
            head = tmp->next;
        }
        head = myhead;
        myhead = new Node(0);
        Node* p = myhead;
        while (head)
        {
            Node* t = head->next;
            p->next = t;
            head->next = t->next;
            head = t->next;
            p = p->next;
        }
        return myhead->next;
    }
};