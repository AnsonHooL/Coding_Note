//
// Created by lenovo on 2021/4/25.
//

class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* head = nullptr;
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        increasingBST(root->left);

        if(prev == nullptr){
            head = root;
            head->left = nullptr;
        } else{
            prev->right = root;
            prev->left  = nullptr;
        }

        prev = root;
        root->left = nullptr;

        increasingBST(root->right);
        return head;
    }
};

/**
 *
给你一棵二叉搜索树，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。


 还要处理将结点全改为null，挺烦人的

 * */