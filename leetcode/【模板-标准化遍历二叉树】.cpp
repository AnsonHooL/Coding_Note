//
// Created by lenovo on 2021/5/25.
//
///非常好记啊其实，简直了牛逼！！！！！！！！！！！！！！！
///一个栈 + NULL标记法

///中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop(); /// 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right) st.push(node->right);  /// 添加右节点（空节点不入栈）

                st.push(node);                          /// 添加中节点
                st.push(NULL); /// 中节点访问过，但是还没有处理，加入空节点做为标记。

                if (node->left) st.push(node->left);    /// 添加左节点（空节点不入栈）
            } else { /// 只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();           /// 将空节点弹出
                node = st.top();    /// 重新取出栈中元素
                st.pop();
                result.push_back(node->val); /// 加入到结果集
            }
        }
        return result;
    }
};
/// 思路：首先压栈先压栈右节点，再左节点，出栈是才会反着来
/// 第二每个结点访问前都会有一个标记，NULL -》访问结点


///前序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左
                st.push(node);                          // 中
                st.push(NULL);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};


///后序遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop();
                st.push(node);                          // 中
                st.push(NULL);

                if (node->right) st.push(node->right);  // 右
                if (node->left) st.push(node->left);    // 左

            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};

