//
// Created by lenovo on 2020/11/30.
//

class Solution1{
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();//hang
        int col = grid[0].size();//lie

        vector<vector<int>> value;
        value.resize(row);
        value[0].push_back(grid[0][0]);

        printf("1:%d\n",value[0][0]);

        for(int i=1;i<col;i++)
        {
            printf("v:%d\n",value[0][i-1] );
            printf("g:%d\n", grid[0][i]);
            value[0].push_back(value[0][i-1] + grid[0][i]);
        }
        for(int i=1;i<row;i++)
        {
            value[i].push_back(value[i-1][0] + grid[i][0]);
        }
        for(int i =1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                int max1 = max(value[i-1][j], value[i][j-1]);
                value[i].push_back(max1 + grid[i][j]);
            }
        }
        return value[row-1][col-1];
    }
};

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int r = grid.size();
        int l = grid[0].size();
        int dp[1000] = {0};
        for (int i=0; i<r; i++){
            for (int j=0; j<l; j++){
                if (j == 0)
                    dp[0] += grid[i][0];
                else
                    dp[j] = grid[i][j] + max(dp[j-1], dp[j]);
            }
        }
        return dp[l-1];
    }
};

/**输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物


简单的二维动态规划，可以简化为一维的空间，看看下面的代码，多简单舒服。优化过后
 *
 *
 *
 * /