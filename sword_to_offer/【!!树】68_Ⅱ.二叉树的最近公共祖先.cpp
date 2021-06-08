//
// Created by lenovo on 2020/12/11.
//

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(root == p) return root;
        if(root == q) return root;

        if(left && right) return root;
        if(left) return left;
        if(right) return right;
        return nullptr;
    }

};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        else{
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if(left && right) return root;
            return left ? left : right;
        }
        return NULL;
    }
};

/***
 *
 *
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

 思路：后序遍历
  左 右 根

  最近的情况是一：在两边 二：其中一个是另一个祖先
  所以根节点等于其中一个就返回即可，判断其左右如果都有，则必是其为最近结点

 *
 *
 *
 *
 *
 * /