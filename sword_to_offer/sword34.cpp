//
// Created by lenovo on 2020/9/24.
//


/** 打印根节点到 “叶子节点” 和为sum的所有路径：前序遍历 而且可以引用节省复制时间和空间 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> re;
        vector<int> path;
        summ = sum;
        int count = 0;
        preorder(re,path,root,count);
        return re;
    }
    void preorder(vector<vector<int>>& re,vector<int>& path, TreeNode* node, int count)
    {
        if(node==NULL) return;
        count += node->val;
        path.push_back(node->val);
        if(count == summ && node->left == NULL && node->right == NULL)
        {
            re.push_back(path);
        }
        if(node->left) preorder(re,path,node->left,count);
        if(node->right) preorder(re,path,node->right,count);
        path.pop_back();
    }
    stack<TreeNode*> mystack;
    int summ;
};