//
// Created by lenovo on 2020/12/26.
//

///给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

///思路一 暴力法：确定 i j位置的矩阵，然后暴力求解



/**
     *    0 0 0 0  0 0 0 0
     *    1 0 1 1  1 0 1 1
     *    0 0 1 1  0 0 2 2
     *    0 0 1 1  0 0 3 3
     *    左边是初始矩阵  ， 可以转化为右边的矩阵， 右边的是每一列， 从上到下， 数有多少个连续1
     *
     *    这样有多少个‘1’，就转化为每一行是一个柱状图，求柱状图的最大矩形面积，调用84题的函数即可
     *
     * */



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;

        vector<int> myhight;
        myhight.push_back(0);  ///哨兵
        myhight.insert(myhight.end(), heights.begin(), heights.end());
        myhight.push_back(0);

        int maxsize = 0;

        stack<int> mystack; mystack.push(0); ///push 柱子的索引
        for(int i = 1; i < myhight.size(); i++)
        {
            int index = mystack.top();
            int colsize = myhight[index]; ///柱子高度
            if(colsize  <  myhight[i])
            {
                mystack.push(i);
                continue;
            }
            else if(colsize == myhight[i]) ///  1,1,1,9 相同的柱子保留一个就行，保留最右的，这样 9柱子 才能算对
            {
                mystack.pop();
                mystack.push(i);
            }

            while (colsize > myhight[i])
            {
                mystack.pop();
                index = mystack.top();
                maxsize = max(maxsize, colsize * (i - index - 1));
                colsize = myhight[index];
            }
            mystack.push(i);
        }
        return maxsize;
    }

    /**
     *    0 0 0 0  0 0 0 0
     *    1 0 1 1  1 0 1 1
     *    0 0 1 1  0 0 2 2
     * */

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> mymatrix(col,0);
        int maxsize = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == '1') mymatrix[j] = mymatrix[j] + 1; ///就一列中连续1的个数， 柱子的高度
                else mymatrix[j] = 0;
            }

            maxsize = max(maxsize, largestRectangleArea(mymatrix));

        }
        return maxsize;
    }
};