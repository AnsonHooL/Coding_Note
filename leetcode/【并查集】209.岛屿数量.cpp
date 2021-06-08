//
// Created by lenovo on 2021/6/6.
//

class Solution {
public:
    int size = 0;

    int findfa(vector<int>& fa, int x){
        if(fa[x] != x){
            return fa[x] = findfa(fa, fa[x]);
        }
        return fa[x];
    }

    void connect(vector<int>& fa, int x, int y){
        int xf = findfa(fa, x);
        int yf = findfa(fa, y);

        if(xf != yf) size--;

        fa[xf] = yf;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> father(m * n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                father[i * n + j] = i * n + j;
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){

                    size++;
                    cout << size <<endl;
                    if(i+1 < m && grid[i+1][j] == '1'){
                        connect(father, i * n + j, (i+1) * n + j);
                        cout << size <<endl;
                    }


                    if(j+1 < n && grid[i][j+1] == '1'){
                        connect(father, i * n + j, i * n + j + 1);
                        cout << size <<endl;
                    }

                }
            }
        }
        return size;

    }
};
/**
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

easy

 *
 * */