//
// Created by lenovo on 2020/12/8.
//

class Solution {
public:
    vector<double> dicesProbability(int n) {
        int dp[15][70] ;
        memset(dp,0,15*70*sizeof(int));
        for(int i=1;i<=6;i++) dp[1][i] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j = i;j <= i*6; j++)
            {
                for(int k = 1;k<=6; k++)
                {
                    if(j-k > 0) dp[i][j] += dp[i-1][j-k];
                    else break;
                }
            }
        }
        double all = pow(6,n);
        vector<double> re;
        for(int i = n;i<=n*6;i++)
        {
            re.push_back(dp[n][i]/all);
        }
        return re;
    }
};

/***
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

 

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

 

示例 1:

输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
示例 2:

输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]


思路：用动态规划的思想，最重要的是思考最后一步怎么规划方程

为了简化分析，我们以投掷 2 枚骰子为例。

我们来模拟计算点数 4 和 点数 6 ，这两种点数各自出现的次数。也就是计算 getCount(2, 4) 和 getCount(2, 6)。

它们的计算公式为：

getCount(2, 4) = getCount(1, 1) + getCount(1, 2) + getCount(1, 3)
getCount(2, 6) = getCount(1,1) + getCount(1,2) + getCount(1,3) + getCount(1,4) + getCount(1,5)
getCount(2, 7) = getCount(1,1) + getCount(1,2) + getCount(1,3) + getCount(1,4) + getCount(1,5) + getCount(1,6)


我们发现递归统计这两种点数的出现次数时，重复计算了
getCount(1, 1) , getCount(1, 2) , getCount(1, 3)






*/