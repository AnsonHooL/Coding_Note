//
// Created by lenovo on 2021/3/15.
//

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> re;
        if(matrix.size() == 0) return re;
        int up = 0;
        int right = matrix[0].size() - 1;
        int down =  matrix.size() - 1;
        int left = 0;
        int count = 0;
        int row  = matrix.size();//hang
        int column = matrix[0].size();//lie

        while(count <  row * column)
        {
            for(int i = 0; i < column; i++)
            {
                if(up < row && matrix[up][i] != 99995555)
                {
                    re.push_back(matrix[up][i]);count++;
                    matrix[up][i] = 99995555;
                }
            }
            up++;
            for(int i = 0; i<row; i++)
            {
                if(right >= 0 && matrix[i][right] != 99995555)
                {
                    re.push_back(matrix[i][right]);count++;
                    matrix[i][right] = 99995555;
                }
            }
            right--;
            for(int i = column -1; i >= 0; i--)
            {
                if(down >=0 && matrix[down][i] != 99995555)
                {
                    re.push_back(matrix[down][i]);count++;
                    matrix[down][i] = 99995555;
                }
            }
            down--;
            for(int i = row -1; i>=0 ; i--)
            {
                if(left < column && matrix[i][left] != 99995555)
                {
                    re.push_back(matrix[i][left]);count++;
                    matrix[i][left] = 99995555;
                }
            }
            left++;
        }
        return re;
    }
};

/**
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

很简单直接将访问过的，放置标记位，然后每次 ++ -- ++ --就行方便极了
 *
 * */