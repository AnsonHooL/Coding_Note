//
// Created by lenovo on 2021/4/13.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int last = -1;
    int minre = INT32_MAX;
    int getMinimumDifference(TreeNode* root) {
        trace(root);
        return minre;
    }

    void trace(TreeNode* root)
    {
        if(!root) return;
        trace(root->left);
        if(last == -1) last = root->val;
        else
        {
            minre = min(minre,root->val - last);
            last = root->val;
        }
        trace(root->right);
    }
};

/**
 *
 * 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。


 * */