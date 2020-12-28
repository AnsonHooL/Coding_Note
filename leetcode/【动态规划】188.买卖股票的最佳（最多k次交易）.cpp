//
// Created by lenovo on 2020/12/28.
//

/**
 * 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。


 * */

class Solution {
public:
    int maxProfit(int kmax, vector<int>& prices) {
        if(prices.size()<=1) return 0;
//        if(kmax > prices.size()/2) return infmaxProfit(prices);
        ///若K很大，可能会溢出，所以这里优化了一下，若K不能大于交易日的一半

        int dp1[kmax + 1][1001]; // 不持有
        int dp2[kmax + 1][1001]; // 持有

        for(int i = 1; i <= kmax; i++)
        {
            dp1[i][0] = 0;
            dp2[i][0] = -prices[0];
        }

        ///就是上一题最多2此交易的拓展罢了，2-》kmax
        for(int i = 1; i < prices.size(); i++)
        {
            for(int k = 1; k <= kmax; k++)
            {
                dp1[k][i] = max(dp1[k][i-1], dp2[k][i-1] + prices[i]); ///昨天没持有不动， 昨天买，今天卖

                if(k > 1)
                    dp2[k][i] = max(dp2[k][i-1], dp1[k - 1][i-1] - prices[i]); ///昨天持有不动， 今天买入
                else if(k == 1)
                    dp2[k][i] = max(dp2[k][i-1], - prices[i]); ///昨天持有不动， 今天买入
            }

        }

        int maxre = 0;
        for(int i = 1; i <= kmax; i++)
        {
            maxre = max(maxre, dp1[i][prices.size() -1]); ///最后算出最大值
        }
        return maxre;
    }

    int infmaxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int dp1[50001] = {0};
        int dp2[50001] = {0};
        dp1[0] = 0; //不持有
        dp2[0] = -prices[0];//持有
        for(int i = 1; i < prices.size(); i++)
        {
            dp1[i] = max(dp1[i-1], dp2[i-1] + prices[i]);
            dp2[i] = max(dp2[i-1], dp1[i-1] - prices[i]); ///昨天持有不动， 今天买入
        }
        return dp1[prices.size() -1];
    }
};
