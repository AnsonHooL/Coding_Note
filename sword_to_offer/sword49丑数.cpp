//
// Created by lenovo on 2020/12/1.
//

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        dp[0] = 1; //动态规划
        int TWO=0,THREE=0,FIVE=0; //保存dp数组索引
        for(int i = 1; i<n; i++)
        {
            //每一个丑数都是由前面的丑数*2*3*5得出来的
            int twoth = dp[TWO] * 2;
            int threeth = dp[THREE] * 3;
            int fiveth = dp[FIVE] * 5;
            dp[i] = min(min(twoth,threeth),fiveth);
            if(dp[i] == twoth) TWO++;
            if(dp[i] == threeth) THREE++;
            if(dp[i] == fiveth) FIVE++;
        }
        return dp[n-1];
    }
};

/**
 * 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

 

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。


 思路：三指针的动态规划
 2：2 4 6 8 10
 3：3 6 9 12 15
 5：5 10 15 20 25
 相当于多路归并排序


 * /
