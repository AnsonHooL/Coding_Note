//
// Created by lenovo on 2020/9/20.
//

/****** 判断树A 和 树B 是否有相同的自结构
 *       两个递归一个是A树的递归
 *       一个是B树的递归
 *       重要是拆成两个递归！牛逼
 * ***/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL || A==NULL) return false;
        bool res;
        if(A->val == B->val)
        {
            res = dfs(A->left,B->left) && dfs(A->right,B->right);
            if(res) return res;
        }
        return  isSubStructure(A->left,B) || isSubStructure(A->right,B);

    }
    bool dfs(TreeNode* A, TreeNode* B)
    {
        bool res;
        if(B == NULL) return true;
        if(A == NULL) return false;
        return (A->val == B->val) && dfs(A->left,B->left) && dfs(A->right,B->right);
    }
};