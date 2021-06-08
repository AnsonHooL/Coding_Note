//
// Created by lenovo on 2021/6/6.
//

class Solution {
public:
    unordered_map<TreeNode*, int> map;
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        if(!root->left && !root->right) return root->val;
        if(map.find(root) != map.end())
            return map[root];

        int left = rob(root->left);
        int right = rob(root->right);

        int leftleft = root->left? rob(root->left->left) : 0;
        int leftright = root->left? rob(root->left->right) : 0;
        int rightleft = root->right? rob(root->right->left) : 0;
        int rigntright = root->right? rob(root->right->right) : 0;

        int result = max(root->val + leftleft + leftright + rightleft + rigntright,
                         left + right);
        map[root] = result;
        return result;
    }
};

/***
 * 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

输出: 7
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.


 *
 * /