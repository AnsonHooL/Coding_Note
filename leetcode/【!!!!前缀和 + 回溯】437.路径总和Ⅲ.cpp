//
// Created by lenovo on 2021/6/9.
//

/*
 * 给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11


 *
*/
///前缀和方法
 /**
  *   10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1


  sum = 8
  那么到3结点，前缀和是18， 18 - 8 = 10， 如果有前缀和为10那么就说明有路径

  *
  *
  * */

class Solution {
public:
    unordered_map<int, int> count;
    int pathSum(TreeNode* root, int sum) {
        ///初始化
        count[0] = 1;
        return helper(root, sum, 0);
    }
    int helper(TreeNode* root, int sum, int prefix_sum) {
        if (!root) return 0;
        int res = 0;
        prefix_sum += root->val;
        res += count[prefix_sum - sum];
        count[prefix_sum]++;
        res += helper(root->left, sum, prefix_sum) + helper(root->right, sum, prefix_sum);
        count[prefix_sum]--;
        return res;
    }
};

///暴力递归
class Solution {
public:
    int count = 0;
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        dfs(root, sum) ;
        pathSum(root->left, sum) ;
        pathSum(root->right, sum);
        return count;
    }
    void dfs(TreeNode* root, int sum) {
        if (!root) return;
        if (sum - root->val == 0) count++;
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
};



