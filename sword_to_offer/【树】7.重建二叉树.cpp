//
// Created by lenovo on 2020/9/13.
//
//重建二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return NULL;
        int val = preorder[0];
        TreeNode* root = new TreeNode(val);
        int i;
        for(i = 0;i<preorder.size();i++)
        {
            if(inorder[i] == val) break;
        }
        if(i == 0) root->left = NULL;
        else
        {
            vector<int>  pre(preorder.begin() + 1,preorder.begin()+1+i);
            vector<int>  in(vector<int>(inorder.begin(),inorder.begin()+i));
            root->left = buildTree(pre,in);
        }
        if(i == preorder.size() -1) root->right = NULL;
        else
        {
            vector<int> pre(preorder.begin()+1+i,preorder.end());
            vector<int> in(vector<int>(inorder.begin()+i+1,inorder.end()));
            root->right = buildTree(pre,in);
        }
        return root;
    }
};


/***
 *
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

 *
 *
 *
 * /