//
// Created by lenovo on 2021/1/30.
//

class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;

public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);///顺序赋值
    }

    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }

    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) { ///为了更高效的合并
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount; ///计算联通分量
        return true;
    }

    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

struct edge
{
    int x;
    int y;
    int value;
    edge(int x, int y, int value): x(x), y(y), value(value) {};

};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        UnionFind U(n * m);
        vector<edge> weightvec;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i + 1 < n)
                {
                    weightvec.emplace_back(i*m+j, (i+1)*m+j, abs(heights[i][j] - heights[i+1][j]));
                }
                if(j + 1 < m)
                {
                    weightvec.emplace_back(i*m+j, i*m+j+1, abs(heights[i][j] - heights[i][j+1]));
                }
            }
        }
        sort(weightvec.begin(), weightvec.end(),
             [](edge lhs, edge rhs) -> bool { return lhs.value < rhs.value;});

        for(auto edge : weightvec)
        {
            U.unite(edge.x, edge.y);
            if(U.connected(0, n*m-1)) return edge.value;
        }
        return 0;
    }
};

/**
 * 你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。

思路：排序体力值，然后从第开始合并，知道首尾能联通

 这题还可以用bfs
 * */