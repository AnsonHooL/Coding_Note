//
// Created by lenovo on 2021/3/28.
//


///中序，左中右
class BSTIterator {
public:
    stack<TreeNode*> s;
//    TreeNode* last = NULL;
    BSTIterator(TreeNode* root) {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* cur = s.top();
        int val = cur->val;
        s.pop();
        cur = cur->right;
        while (cur)
        {
            s.push(cur);
            cur = cur->left;
        }
        return val;
    }

    bool hasNext() {
        return !s.empty();
    }
};

///前序
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        if(root)
            s.push(root);
    }

    int next() {
        TreeNode* cur = s.top();
        s.pop();
        if(cur->right) s.push(cur->right);
        if(cur->left)  s.push(cur->left);
        return cur->val;
    }

    bool hasNext() {
        return !s.empty();
    }
};

todo:后序
///感觉不难，加一个判断就行，上一个访问的是否是他的右节点即可。或者没有右节点


/**
 * 实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
int next()将指针向右移动，然后返回指针处的数字。
注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。

你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。


 *
 * */