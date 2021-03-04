//
// Created by lenovo on 2021/2/22.
//

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                int cur = matrix[i][j];
                if(i + 1 < row && j + 1 < col && matrix[i+1][j+1] != cur)
                    return false;
            }
        }
        return true;
    }
};

/**
 * 给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。

如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。

 

思路：就是从左到右遍历，是否和右下的元素相等即可，巧妙啊
 *
 * */