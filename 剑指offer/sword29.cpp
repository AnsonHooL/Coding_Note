//
// Created by lenovo on 2020/9/20.
//


/***** 顺时针打印矩阵 重要的是边界的确定 也没啥办法。。。细心******/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> f;
        if(matrix.size() == 0) return f;
        int row = matrix.size();
        int col = matrix[0].size();
        int rowlow = 0;
        int collow = 0;
        int i = 0;
        int j = 0;
        int count=0;
        while(count < matrix.size() * matrix[0].size())
        {
            if(count==matrix.size() * matrix[0].size()) break;
            for(;j<col;j++)
            {
                f.push_back(matrix[i][j]);
                //std::cout << matrix[i][j]<< std::endl;
                count++;
            }
            if(count==matrix.size() * matrix[0].size()) break;
            j--;
            i++;
            rowlow++;
            for(;i<row;i++)
            {
                f.push_back(matrix[i][j]);
                //std::cout << matrix[i][j]<< std::endl;
                count++;
            }
            if(count==matrix.size() * matrix[0].size()) break;
            col--;
            j--;
            i--;
            for(;j>=collow;j--)
            {
                f.push_back(matrix[i][j]);
                //std::cout << matrix[i][j]<< std::endl;
                count++;
            }
            if(count==matrix.size() * matrix[0].size()) break;
            row--;
            j++;
            i--;
            for(;i>=rowlow;i--)
            {
                f.push_back(matrix[i][j]);
                //std::cout << matrix[i][j]<< std::endl;
                count++;
            }
            if(count==matrix.size() * matrix[0].size()) break;
            j++;
            i++;
            collow++;
        }
        return f;
    }
};