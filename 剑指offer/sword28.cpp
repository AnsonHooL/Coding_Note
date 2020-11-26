//
// Created by lenovo on 2020/9/20.
//


/*** 判断一棵树是不是对称的用递归做就行了**/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        else return doisSymmetric(root->left,root->right);
    }
    bool doisSymmetric(TreeNode* A,TreeNode* B) {
        if(A == NULL && B == NULL) return true;
        if(A == NULL || B == NULL) return false;
        return A->val==B->val && doisSymmetric(A->left,B->right) && doisSymmetric(A->right,B->left);
    }
};