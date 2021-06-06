//
// Created by lenovo on 2021/6/4.
//

class Solution {
public:
    int prev = 596523 ;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool left = isValidBST(root->left);
        if(prev != 596523 && prev >= root->val)
            return false;
        prev = root->val;
        bool right = isValidBST(root->right);
        return left&&right;
    }
};