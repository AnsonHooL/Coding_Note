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
        queue<TreeNode*> myqueue;
        if(!root) return re;
        else myqueue.push(root);
        int depth = 0; ///偶数层正序，奇数层反转
        while(!myqueue.empty())
        {
            int size = myqueue.size();
            vector<int> onelayer;
            for(int i = 0; i < size; i++) ///这里已经知道了每一层的size了，不需要什么结点进行标记
            {
                TreeNode* tmp = myqueue.front();
                myqueue.pop();
                onelayer.push_back(tmp->val);
                if(tmp->left) myqueue.push(tmp->left);
                if(tmp->right) myqueue.push(tmp->right);
            }
//            if(depth % 2 == 1)
//                reverse(onelayer.begin(),onelayer.end()); ///偶数层正序，奇数层反转
            re.push_back(onelayer);
            depth++;
        }
        return re;
    }
};
