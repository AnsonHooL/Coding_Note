//
// Created by lenovo on 2021/4/11.
//

class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 1;
        int Two = 0;
        int Three = 0;
        int Five = 0;
        vector<int> dp(n,1);
        while(i < n)
        {
            int dp2 = dp[Two] * 2;
            int dp3 = dp[Three] * 3;
            int dp5 = dp[Five] * 5;
            dp[i] = min(min(dp2, dp3), dp5);

            if(dp[i] == dp2) Two++;
            if(dp[i] == dp3) Three++;
            if(dp[i] == dp5) Five++;
            i++;
        }
        return dp[n-1];
    }
};


/**
 * 阿西吧、阿西吧
 * 动态规划啊这次，己然想到了丑数是由丑数生成的，那么
 * 必然是要用到以前的数据
 * 动态规划就是需要用一个记账本啊，把以前的东西记住，先开空间，再想优化的事情
 *
 * */