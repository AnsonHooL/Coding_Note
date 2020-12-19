//
// Created by lenovo on 2020/12/19.
//

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        ///先沿着对角线左上-右下旋转
        for(int i = 0; i<length; i++)
        {
            for(int j = length-1; j>=i; j--)
            {
                swap(matrix[j][i],matrix[i][j]);
            }
        }
        ///再沿着竖线反转
        for(int i = 0; i<length; i++)
        {
            for(int j = 0; j < length/2 ;j++)
            {
                swap(matrix[i][j],matrix[i][length - 1 - j]);
            }
        }
    }
};


///先沿着对角线左上-右下旋转，再沿着竖线反转

/**
 * 给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

原地旋转90°矩阵，等于先对角线，再沿着竖线反转
 *
 *
 *
 *
 * 数组将前几个原地挪到后面也是一样 0 1 2 3 4 5 6 7 8 -> 3 4 5 6 7 8 0 1 2
 *  先前后分别反转，再整体反转  2 1 0 8 7 6 5 4 3  -> 3 4 5 6 7 8 0 1 2
 *
 * */