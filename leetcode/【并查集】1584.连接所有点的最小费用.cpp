//
// Created by lenovo on 2021/1/19.
//

class edge{
public:
    int x;
    int y;
    int w;
    edge(int x, int y, int w)
            :x(x), y(y), w(w)
    {}
    bool operator<(const edge& a)
    {
        return w < a.w;
    }
};


class Solution {
public:
    int find(int x, vector<int>& father)
    {
        if(x == father[x]) return x;
        else
        {
            father[x] = find(father[x], father);
            return father[x];
        }
    }
    void merge(int x, int y, vector<int>& father)
    {
        int xf = find(x, father);
        int yf = find(y, father);
        father[xf] = yf;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> father(n);
        vector<edge> edges;

        for(int i = 0; i < n; i++) father[i] = i;

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                edges.emplace_back(i,j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
            }

        }
        sort(edges.begin(), edges.end());

        // for(auto& edge : edges) cout<< edge.w <<endl;

        int res = 0;
        for(auto& edge : edges)
        {
            int x = edge.x;
            int y = edge.y;
            if(find(x,father) == find(y,father)) continue;
            else
            {
                merge(x, y, father);
                res += edge.w;
            }
        }
        return res;

    }
};

/**
 * 给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。

连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。


 思路：最小生成树，这里用的是kustra，用边排序 + 并查集 判断是否为环，写的，还可以用prim

 * */