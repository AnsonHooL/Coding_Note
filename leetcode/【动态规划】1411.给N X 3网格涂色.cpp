//
// Created by lenovo on 2021/3/6.
//

class Solution {
public:
    int numOfWays(int n) {
        long abc = 6;
        long aba = 6;

        for(int i = 1; i < n; i++)
        {
            long tmp = aba;
            aba = (abc * 2 + aba * 3)% (1000000007);
            abc = (abc * 2 + tmp * 2)% (1000000007);
        }
        return (abc + aba) % (1000000007);

    }
};

/**
 *
 *
你有一个 n x 3 的网格图 grid ，你需要用 红，黄，绿 三种颜色之一给每一个格子上色，且确保相邻格子颜色不同（也就是有相同水平边或者垂直边的格子颜色不同）。

给你网格图的行数 n 。

请你返回给 grid 涂色的方案数。由于答案可能会非常大，请你返回答案对 10^9 + 7 取余的结果。

 */