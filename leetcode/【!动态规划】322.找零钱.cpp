//
// Created by lenovo on 2021/3/16.
//


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT32_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(auto coin : coins)
            {
                if(i >= coin && dp[i - coin] != INT32_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        if(dp[amount] == INT32_MAX) return -1;
        else
            return dp[amount];
    }
};
/**
 * 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。

 
 *
 * */