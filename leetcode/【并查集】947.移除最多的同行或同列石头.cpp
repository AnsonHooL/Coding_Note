//
// Created by lenovo on 2021/1/15.
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

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> father(n,0);
        unordered_map<int, int> mymapcol;
        unordered_map<int, int> mymaprow;
        for(int i = 0; i < n; i++) father[i] = i;
        int x = 0;
        for(auto stone : stones)
        {
            if(mymaprow.find(stone[0]) != mymaprow.end())
            {
                merge(father, mymaprow[stone[0]], x);
            }
            mymaprow[stone[0]] = x;
            if(mymapcol.find(stone[1]) != mymapcol.end())
            {
                merge(father, mymapcol[stone[1]], x);
            }
            mymapcol[stone[1]] = x;
            x++;
        }
        vector<int> count(2000, 0);
        int re = 0;
        for(int i = 0; i < n; i++)
        {
            int xf = findfather(father, i);
            if(count[xf] == 0)
            {
                re++;
                count[xf] = 1;
            }
        }
        return  n - re;
    }
};

/**
 * n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头。

如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头。

给你一个长度为 n 的数组 stones ，其中 stones[i] = [xi, yi] 表示第 i 块石头的位置，返回 可以移除的石子 的最大数量。

 

示例 1：

输入：stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
输出：5
解释：一种移除 5 块石头的方法如下所示：
1. 移除石头 [2,2] ，因为它和 [2,1] 同行。
2. 移除石头 [2,1] ，因为它和 [0,1] 同列。
3. 移除石头 [1,2] ，因为它和 [1,0] 同行。
4. 移除石头 [1,0] ，因为它和 [0,0] 同列。
5. 移除石头 [0,1] ，因为它和 [0,0] 同行。
石头 [0,0] 不能移除，因为它没有与另一块石头同行/列。

思路：行列并查集，然后最后计算并查集的数量
 * */