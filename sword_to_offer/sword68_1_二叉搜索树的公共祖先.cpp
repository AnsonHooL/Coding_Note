//
// Created by lenovo on 2020/12/11.
//

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int low = q->val;
        int high = p->val;
        if(high < low) swap(low,high);
        return help(root,low,high);
    }
    TreeNode* help(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        if(root->val == low || root->val == high) return root;
        if(root->val> low && root->val < high) return root;
        if(root->val < low && root->val<high) return help(root->right,low,high);
        if(root->val > low && root->val>high) return help(root->left,low,high);
        return NULL;
    }
};

/***
 *
 * 二叉搜索树的最近公共祖先
 * 只需要确定一个节点在左一个结点在右即可
 *
 *
 *
 *
 * /