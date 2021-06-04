//
// Created by lenovo on 2021/5/14.
//

/class Solution {
public:
    int numWays(int steps, int arrLen) {

        vector<vector<int>> dp(steps + 1, vector<int>(arrLen,0));
        int mod = 1000000007;

        int max = min(steps / 2, arrLen - 1);
        dp[0][0] = 1;

        for(int i = 1; i <= steps;i++){

            for(int j = 0;j <= max;j++){

                dp[i][j] += dp[i-1][j];

                dp[i][j] = dp[i][j] % mod;

                if(j+1 <= max)
                    dp[i][j] += dp[i-1][j+1];

                dp[i][j] = dp[i][j] % mod;

                if(j-1 >= 0)
                    dp[i][j] += dp[i-1][j-1];

                dp[i][j] = dp[i][j] % mod;
            }
        }

        return dp[steps][0];
    }
};

/**
 * 有一个长度为 arrLen 的数组，开始有一个指针在索引 0 处。

每一步操作中，你可以将指针向左或向右移动 1 步，或者停在原地（指针不能被移动到数组范围外）。

给你两个整数 steps 和 arrLen ，请你计算并返回：在恰好执行 steps 次操作以后，指针仍然指向索引 0 处的方案数。

由于答案可能会很大，请返回方案数 模 10^9 + 7 后的结果。

 

示例 1：

输入：steps = 3, arrLen = 2
输出：4
解释：3 步后，总共有 4 种不同的方法可以停在索引 0 处。
向右，向左，不动
不动，向右，向左
向右，不动，向左
不动，不动，不动


 *
 * */