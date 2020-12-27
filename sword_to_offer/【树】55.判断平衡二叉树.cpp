//
// Created by lenovo on 2020/12/3.
//

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(f(root->right) - f(root->left)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int f(TreeNode* root)
    {
        if(root == NULL) return 0;
        else return 1+max(f(root->left),f(root->right));
    }
};

/**
 * 示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false

思路：递归判断两个子树是否平衡且，子树高度差小于1
 * */