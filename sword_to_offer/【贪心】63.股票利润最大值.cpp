//
// Created by lenovo on 2020/12/9.
//

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

/***
 *
 *示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

思路：动态规划，维护n-1的最小值，然后第n天减去最小值看，是否有最高利润，再维护最小值
 * /