//
// Created by lenovo on 2020/12/3.
//

///标准模板
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int level = 0;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        while (!myqueue.empty())
        {
            int size = myqueue.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* tmp = myqueue.front();
                myqueue.pop();
                if(tmp->left) myqueue.push(tmp->left);
                if(tmp->right) myqueue.push(tmp->right);
            }
            level++;
        }
        return level;
    }
};
/***
 *
 *
 *
 *
 *
 * 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7

思路：层次遍历即可，用队列实现

 *
 * */