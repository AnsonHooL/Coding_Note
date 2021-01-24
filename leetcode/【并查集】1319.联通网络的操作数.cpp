//
// Created by lenovo on 2021/1/23.
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind Uset(n);
        int unused = 0;
        for(auto conn : connections)
        {
            if(!Uset.unite(conn[0], conn[1]))
                unused++;
        }
        if(Uset.setCount == 1) return 0;
        else if(unused < Uset.setCount - 1) return -1;
        return Uset.setCount - 1;
    }
};

/**
用以太网线缆将 n 台计算机连接成一个网络，计算机的编号从 0 到 n-1。线缆用 connections 表示，其中 connections[i] = [a, b] 连接了计算机 a 和 b。

网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。

给你这个计算机网络的初始布线 connections，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。请你计算并返回使所有计算机都连通所需的最少操作次数。如果不可能，则返回 -1


 思路：套并查集的模板，直接计算最后的联通分量，然后看看有多少跟网线是没用的就行
 * */