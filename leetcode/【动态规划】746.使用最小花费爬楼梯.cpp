//
// Created by lenovo on 2020/12/21.
//

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        dp.resize(cost.size() + 2);
        vector<int> mycost;
        mycost.push_back(0);
        for(auto x : cost) { mycost.push_back(x);}
        mycost.push_back(0);
        assert(mycost.size() == dp.size());

        dp[0] = 0;
        dp[1] = mycost[1];
        for(int i = 2; i < mycost.size(); i++)
        {
            dp[i] = min(dp[i-1] + mycost[i], dp[i-2] + mycost[i]);
        }
        return dp.back();
    }
};

/***
 * 数组的每个索引作为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。

每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。

您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。

示例 1:

输入: cost = [10, 15, 20]
输出: 15
解释: 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。
 示例 2:

输入: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
输出: 6
解释: 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。


 思路：题目不说人话，有默认花费为0的第0层和最后一层台阶，把这个想清楚就简单了

 * /