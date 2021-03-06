//
// Created by lenovo on 2020/9/25.
//
/** 就是将二叉搜索树变成 有序双向链表 原地更新 -+*
 *  链表
 *  按照中序遍历的顺序
 *
 *
 *
 *
 *
 * **/
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        pre = NULL;
        dfs(root);
        pre->right = head;
        head->left = pre;
        return head;
    }
    void dfs(Node* root) ///递归中序遍历
    {
        if(root == NULL) return;
        dfs(root->left);
        if(pre == NULL) ///第一个结点记录下来
        {
            pre  = root;
            head = root;
        }
        else
        {
            root->left = pre;
            pre->right = root;
            pre = root;
        }
        dfs(root->right);
    }

    Node* pre;    ///记录上一个结点是啥
    Node* head;   ///记录头节点
};