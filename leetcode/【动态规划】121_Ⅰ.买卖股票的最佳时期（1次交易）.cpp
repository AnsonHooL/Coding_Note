//
// Created by lenovo on 2020/12/28.
//

/**
 * 定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

 

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。

只能买卖一次

 * */




///思路一：维护一个之前的历史最低价
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int low = INT32_MAX;
        int value = 0;
        for(int i = 0;i<prices.size();i++)
        {
            if(prices[i] - low > value) value =  prices[i] - low;
            if(prices[i] < low) low = prices[i];
        }
        return value;
    }
};

///思路二：用状态机套模板
///dp1 是不持有股票的dp数组
///dp2 是持有股票
///只能交易一次，注意，dp2今天买入是 -prices
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int dp1[50001] = {0};
        int dp2[50001] = {0};
        dp1[0] = 0; //不持有
        dp2[0] = -prices[0];//持有
        for(int i = 1; i < prices.size(); i++)
        {
            dp1[i] = max(dp1[i-1], dp2[i-1]+prices[i]);
            dp2[i] = max(dp2[i-1], -prices[i]);      ///昨天持有不动， 今天买入，注意，dp2今天买入是 -prices
        }
        return dp1[prices.size() -1];
    }
};