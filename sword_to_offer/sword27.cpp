//
// Created by lenovo on 2020/9/20.
//

/** 输出镜像树 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL) return NULL;
        swap(root->right,root->left);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
