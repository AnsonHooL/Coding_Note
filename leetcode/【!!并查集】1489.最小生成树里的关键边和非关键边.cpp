//
// Created by lenovo on 2021/1/21.
//


// 并查集模板
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;

public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) { ///edge 点1，点2，权重
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }
        ///排序根据权重
        sort(edges.begin(), edges.end(), [] (const auto& u, const auto& v) -> bool {
            return u[2] < v[2];
        });

        // 计算 value
        UnionFind uf_std(n);
        int value = 0;
        for (int i = 0; i < m; ++i) {
            if (uf_std.unite(edges[i][0], edges[i][1])) {
                value += edges[i][2];
            }
        }

        vector<vector<int>> ans(2);

        for (int i = 0; i < m; ++i) {
            // 判断是否是关键边
            UnionFind uf(n);
            int v = 0;
            for (int j = 0; j < m; ++j) {
                if (i != j && uf.unite(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }
            ///如果少了一条边，就不是联通图，或者最小生成图变大了，则是关键边
            if (uf.setCount != 1 || (uf.setCount == 1 && v > value)) {
                ans[0].push_back(edges[i][3]);
                continue;
            }

            // 判断是否是伪关键边
            ///能存在最小生成图，且不是关键边则是，非关键边
            uf = UnionFind(n);
            uf.unite(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for (int j = 0; j < m; ++j) {
                if (i != j && uf.unite(edges[j][0], edges[j][1])) {
                    v += edges[j][2];
                }
            }
            if (v == value) {
                ans[1].push_back(edges[i][3]);
            }
        }

        return ans;
    }
};

/**
 * 给你一个 n 个点的带权无向连通图，节点编号为 0 到 n-1 ，同时还有一个数组 edges ，其中 edges[i] = [fromi, toi, weighti] 表示在 fromi 和 toi 节点之间有一条带权无向边。最小生成树 (MST) 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。

请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。

请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。

 
 * */