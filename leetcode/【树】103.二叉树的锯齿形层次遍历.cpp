//
// Created by lenovo on 2020/12/22.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
            if(depth % 2 == 1)
                reverse(onelayer.begin(),onelayer.end()); ///偶数层正序，奇数层反转
            re.push_back(onelayer);
            depth++;
        }
        return re;
    }
};

/**
 *给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

思路：标准模板 + 偶数层正序，奇数层反转 +

 *
 *
 * */