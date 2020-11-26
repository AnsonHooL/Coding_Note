//
// Created by lenovo on 2020/9/22.
//


/****    打印每一层的数字   ****/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> re;
        if(root == NULL) return re;
        int layer = 0;
        re.emplace_back(vector<int>());
        TreeNode* listen = root;
        TreeNode* back   = NULL;
        A.push(root);
        while(!A.empty())
        {
            TreeNode* tmp = A.front();
            A.pop();
            re[layer].push_back(tmp->val);
            if(tmp->left)
            {
                A.push(tmp->left);
                back = tmp->left;
            }
            if(tmp->right)
            {
                A.push(tmp->right);
                back= tmp->right;
            }
            if(tmp == listen)
            {
                listen = back;
                re.emplace_back(vector<int>());
                layer++;
            }
        }
        re.pop_back();
        return re;
    }
    queue<TreeNode*> A;
};

