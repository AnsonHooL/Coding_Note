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


///有一个偷鸡版本， 确定上下左右的边界，每次边界移动一位，标记是否打印过数字，然后把整行整列进行打印

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
