//
// Created by lenovo on 2021/6/4.
//

class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> map;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        map = vector<vector<bool>>(m, vector<bool>(n, false));


        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                if(dfs(board, i, j, word, 0))

                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int row, int col, string word, int depth){


        if(row >= m || row < 0|| col >= n || col < 0) return false;

        if(map[row][col] == true) return false;

        if(board[row][col] == word[depth]){

            map[row][col] = true;

            if(depth + 1 == word.size()) return true;

            bool res = dfs(board, row-1, col, word, depth+1)||
                       dfs(board, row+1, col, word, depth+1)||
                       dfs(board, row, col-1, word, depth+1)||
                       dfs(board, row, col+1, word, depth+1);

            map[row][col] = false;

            return res;

        }
        return false;
    }
};

/**
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

思路：
 很简单的暴搜  + 字典保存访问记录
 *
 * */