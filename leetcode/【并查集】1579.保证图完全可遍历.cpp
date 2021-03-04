//
// Created by lenovo on 2021/1/27.
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

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) { ///type ui uj
        UnionFind U(n);
        int nsize = edges.size();
        vector<vector<int>> edges_Alice;
        vector<vector<int>> edges_Bob;
        int need = 0;
        for(const auto& edge : edges)
        {
            if(edge[0] == 1) edges_Alice.push_back(edge);
            else if(edge[0] == 2) edges_Bob.push_back(edge);
            else if(edge[0] == 3)
            {
                if(U.unite(edge[1] - 1, edge[2]- 1)) need++;
            }
        }
        if(U.setCount == 1) return nsize - need;

        UnionFind Tmp = U;
        for(const auto& edge : edges_Alice) ///Alice
        {
            if(Tmp.unite(edge[1] - 1, edge[2] - 1)) need++;
        }
        if(Tmp.setCount > 1)
            return -1; ///不连通

        Tmp = U;
        for(const auto& edge : edges_Bob) ///Bob
        {
            if(Tmp.unite(edge[1] - 1, edge[2] - 1)) need++;
        }
        if(Tmp.setCount > 1)
            return -1; ///不连通

        return nsize - need;
    }
};
/**
 *Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3  种类型的边：

类型 1：只能由 Alice 遍历。
类型 2：只能由 Bob 遍历。
类型 3：Alice 和 Bob 都可以遍历。
给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi 之间存在类型为 typei 的双向边。请你在保证图仍能够被 Alice和 Bob 完全遍历的前提下，找出可以删除的最大边数。如果从任何节点开始，Alice 和 Bob 都可以到达所有其他节点，则认为图是可以完全遍历的。

返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1

思路：先用类型三的边，再各自用边即可。so easy
 *
 * */