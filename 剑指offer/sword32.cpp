//
// Created by lenovo on 2020/9/22.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> re;
        if(root == NULL) return re;
        A.push(root);
        while(!A.empty())
        {
            TreeNode* tmp = A.front();
            A.pop();
            re.push_back(tmp->val);
            if(tmp->left)  A.push(tmp->left);
            if(tmp->right) A.push(tmp->right);

        }
        return re;
    }
    queue<TreeNode*> A;
};