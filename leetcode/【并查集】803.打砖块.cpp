//
// Created by lenovo on 2021/1/17.
//

class DJset
{
public:
    vector<int> sz; ///保存父节点(作为根节点), 旗下有多少个结点
    vector<int> father;
    DJset(int n) :
            sz(n), father(n)
    {
        for(int i = 0; i < n; i++)
        {
            father[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x)
    {
        if(x == father[x]) return x;
        else
        {
            father[x] = find(father[x]);
            return father[x];
        }
    }
    void merge(int x, int y)
    {
        int xf = find(x);
        int yf = find(y);
        if(xf == yf) ///这里要返回
            return;
        father[xf] = yf;
        sz[yf] += sz[xf];
    }


    int size(int x)
    {
        return sz[find(x)];
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<vector<int>> copy = grid; ///拷贝一份初始状态

        for(auto hit : hits)
        {
            copy[hit[0]][hit[1]] = 0; ///先还原最后的状态
        }
        int n = grid.size(); ///行
        int m = grid[0].size(); ///列

        DJset djset(n * m + 1);

        for(int i = 0; i < n ; i++) ///构建独立的联通分量
        {
            for(int j = 0; j < m; j++)
            {
                if(copy[i][j] == 1) ///如果最存在这个块，没被消灭，构建独立联通分量
                {
                    if(i == 0)
                        djset.merge(i * m + j , n * m);
                    if(j > 0 && copy[i][j-1] == 1)
                        djset.merge(i * m +  j, i * m + j - 1);
                    if(i > 0 && copy[i-1][j] == 1)
                        djset.merge(i * m + j, (i -1 ) * m + j);
                }
            }
        }

        vector<vector<int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        vector<int> res(hits.size());
        for(int i = hits.size() - 1; i >= 0; i--)
        {
            int r = hits[i][0];
            int c = hits[i][1];
            if(grid[r][c] == 0) continue;
            int old = djset.size(n * m);
            if(r == 0) djset.merge(r * n + c, n * m);

            for(auto dir : dirs)
            {
                int r1 = r + dir[0];
                int c1 = c + dir[1];
                if(r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && copy[r1][c1] == 1) ///相邻的要存在才行
                {
                    djset.merge(r * m + c, r1 * m + c1);
                }
            }
            int cur = djset.size(n * m);
            res[i] = max(0, cur - old - 1); ///有一个不算，打掉那个
            copy[r][c] = 1;

        }

        return res;
    }
};

/**
 *有一个 m x n 的二元网格，其中 1 表示砖块，0 表示空白。砖块 稳定（不会掉落）的前提是：

一块砖直接连接到网格的顶部，或者
至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时
给你一个数组 hits ，这是需要依次消除砖块的位置。每当消除 hits[i] = (rowi, coli) 位置上的砖块时，对应位置的砖块（若存在）会消失，然后其他的砖块可能因为这一消除操作而掉落。一旦砖块掉落，它会立即从网格中消失（即，它不会落在其他稳定的砖块上）。

返回一个数组 result ，其中 result[i] 表示第 i 次消除操作对应掉落的砖块数目。

注意，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。

 

示例 1：

输入：grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
输出：[2]
解释：
网格开始为：
[[1,0,0,0]，
 [1,1,1,0]]
消除 (1,0) 处加粗的砖块，得到网格：
[[1,0,0,0]
 [0,1,1,0]]
两个加粗的砖不再稳定，因为它们不再与顶部相连，也不再与另一个稳定的砖相邻，因此它们将掉落。得到网格：
[[1,0,0,0],
 [0,0,0,0]]
因此，结果为 [2] 。


 思路：并查集 + 逆序
 先假设所有砖块都被hit了，然后构建联通分量，然后虚拟一个房顶结点，他作为父节点，他旗下有多少结点，就说明多少是稳固的，
 然后逆序回去，每次hit，就补回一块砖头，看现在有多少是稳固的砖头，计算差值，就知道每次掉落多少砖头

 * */