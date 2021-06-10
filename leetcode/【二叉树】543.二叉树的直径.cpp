//
// Created by lenovo on 2021/6/10.
//

class Solution {
public:
    int maxsum = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        trace(root);
        return maxsum;
    }
    int height(TreeNode* root){
        if(!root) return 0;
        else return max(height(root->left), height(root->right)) + 1;
    }
    void trace(TreeNode* root){
        if(!root) return;
        trace(root->left);
        trace(root->right);

        int r = height(root->left) + height(root->right);
        maxsum = max(maxsum, r);
    }
};

/**
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 

示例 :
给定二叉树

          1
         / \
        2   3
       / \
      4   5


 *
 * */