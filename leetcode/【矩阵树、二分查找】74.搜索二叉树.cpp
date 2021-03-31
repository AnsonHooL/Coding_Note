//
// Created by lenovo on 2021/3/30.
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size() - 1;
        int m = 0;
        int n = col;
        while(m < row && n >= 0)
        {
            if(target == matrix[m][n]) return true;
            else if(target < matrix[m][n]) n--;
            else m++;
        }
        return false;
    }
};


/**
 *
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。




 右上角是二叉树的根节点，向左，向下
 *
 * */