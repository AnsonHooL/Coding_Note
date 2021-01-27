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