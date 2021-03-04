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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        UnionFind U(n * m);
        vector<edge> weightvec;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i + 1 < n)
                {
                    weightvec.emplace_back(i*m+j, (i+1)*m+j, max(grid[i][j], grid[i+1][j]));
                }
                if(j + 1 < m)
                {
                    weightvec.emplace_back(i*m+j, i*m+j+1, max(grid[i][j], grid[i][j+1]));
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
 *一个 N x N 的坐标方格 grid 中，每一个方格的值 grid[i][j] 表示在位置 (i,j) 的平台高度。

现在开始下雨了。当时间为 t 时，此时雨水导致水池中任意位置的水位为 t 。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。

你从坐标方格的左上平台 (0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台 (N-1, N-1)？

 

示例 1:

输入: [[0,2],[1,3]]
输出: 3
解释:
时间为0时，你位于坐标方格的位置为 (0, 0)。
此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。

等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置


思路：泳池同时联通的条件是淹没两个平台，就是说选取高的作为权值，高的才能被淹没

 *
 * */