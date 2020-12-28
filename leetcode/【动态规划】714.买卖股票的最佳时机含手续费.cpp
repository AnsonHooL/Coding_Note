//
// Created by lenovo on 2020/12/17.
//
/**
 * 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

示例 1:

输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

 *
 *
 * */

///套模板
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp1[50001] = {0};
        int dp2[50001] = {0};
        dp1[0] = 0; //不持有
        dp2[0] = -prices[0];//持有
        for(int i = 1; i < prices.size(); i++)
        {
            dp1[i] = max(dp1[i-1], dp2[i-1] + prices[i] - fee); ///昨天没持有今天不动， 昨天持有，今天买
            dp2[i] = max(dp2[i-1], dp1[i-1] - prices[i]); ///昨天持有今天不动， 今天买入
        }
        return dp1[prices.size() -1];
    }
};



///思路：用多维的动态规划做，方程是用每天的最高收益，推出下一天的最高收益
///注意这里是可以多次买卖的，多了一个状态，持有股票和不持有股票的最高收益
///当天的持有股票收益 = max{昨天持有股票，昨天不持有股票 + 今天买}
///当天的不持有股票收益 = max{昨天不持有股票 + 昨天持有股票+今天卖}



///和上面相反，思路一致
///dp1[i] = max(dp1[i-1], dp2[i-1] - prices[i]) （第二项表示在第i天买入股票）持有股票
///dp2[i] = max(dp2[i-1], dp1[i-1] + prices[i] - fee) （第二项表示在第i天将股票卖出，需扣除手续费）不持有股票