//
// Created by lenovo on 2020/12/3.
//

///栈
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> mystack;
        TreeNode* tmp = root;
        int count = 0;
        while (tmp)
        {
            mystack.push(tmp);
            tmp = tmp->right;
        }
        while(!mystack.empty())
        {
            TreeNode* read = mystack.top();
            mystack.pop();
            count++;
            if(count == k) return read->val;
            tmp = read->left;
            while (tmp)
            {
                mystack.push(tmp);
                tmp = tmp->right;
            }
        }
        return 0;
    }
};

///递归
class Solution {
public:
    int val;
    int kthLargest(TreeNode* root, int k) {
        int count = 0;
        dfs(root, count,k);
        return val;
    }
    void dfs(TreeNode* root, int& count, int k)
    {
        if(!root || count >= k) return;
        dfs(root->right, count,k);
        if(++count == k) val = root->val;
        dfs(root->left, count, k);
    }
};

/***
 * 示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4

 思路：逆序的中序搜索即可，这里用栈stl实现了

 * **/