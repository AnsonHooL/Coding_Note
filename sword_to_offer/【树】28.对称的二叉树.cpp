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

/***例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

 注意这里不能分成两半去解决，因为要 比较 左子树 和 右子树是否相同！！


 /