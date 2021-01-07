//
// Created by lenovo on 2021/1/7.
//

class Solution {
public:
    int findfather(vector<int>& father, int x)
    {
        if(father[x] != x)
        {
            int xfather = findfather(father, father[x]);
            father[x] = xfather;
            return xfather;

        } else return x;
    }


    void merge(vector<int>& father, int x, int y)
    {
        int xfather = findfather(father, x);
        int yfather = findfather(father, y);
        father[xfather] = yfather;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> father(n,0);
        for(int i = 0; i < n; i++) father[i] = i;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(isConnected[i][j]) merge(father, i, j);
            }
        }
        vector<int> flag(n,0);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            int root = findfather(father,i);
            if(flag[root] == 0)
            {
                count++;
                flag[root] = 1;
            }
        }
        return count;
    }
};

/**
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。


 思路: 并查集的思路，直接并查就完事了，最后看有多少个集合
 *
 * */
