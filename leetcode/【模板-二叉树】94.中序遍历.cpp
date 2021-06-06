//
// Created by lenovo on 2021/6/4.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)   return {};

        vector<int> result;
        midorder(root, result);
        return result;
    }

    void midorder(TreeNode* node, vector<int>& v){
        stack<TreeNode*> S;
        S.push(node);
        while(!S.empty()){
            TreeNode* cur = S.top();
            S.pop();
            if(cur){
                if(cur->right)
                    S.push(cur->right);

                S.push(cur);
                S.push(nullptr);

                if(cur->left)
                    S.push(cur->left);

            } else{
                TreeNode* n = S.top();
                S.pop();
                v.push_back(n->val);
            }
        }
    }
};