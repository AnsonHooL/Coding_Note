//
// Created by lenovo on 2021/4/16.
//




class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int N = s1.size();
        vector<vector<vector<bool>>> dp(N, vector<vector<bool>>(N, vector<bool>(N + 1, false)));
        ///dp[i][j][k],s1：i开始，s2：j开始，长度为k的字符串可以转换成功
        /// k = 1

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(s1[i] == s2[j])
                    dp[i][j][1] = true;
            }
        }

        for(int k = 2; k <= N; k++)
        {
            for(int i = 0; i <= N - k; i++)
            {
                for(int j = 0; j <= N - k; j++)
                {
                    for(int m = 1; m < k; m++)
                    {
                        ///两种情况，分块的顺序一样
                        if(dp[i][j][m] && dp[i+m][j+m][k-m])
                        {
                            dp[i][j][k] = true;
                            break;
                        }
                        ///两种情况，分块的顺序不一样
                        if(dp[i][j + k - m][m] && dp[i+m][j][k-m])
                        {
                            dp[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[0][0][N];

    }
};


/**
 * 使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
如果字符串的长度为 1 ，算法停止
如果字符串的长度 > 1 ，执行下述步骤：
在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。

 

示例 1：

输入：s1 = "great", s2 = "rgeat"
输出：true
解释：s1 上可能发生的一种情形是：
"great" --> "gr/eat" // 在一个随机下标处分割得到两个子字符串
"gr/eat" --> "gr/eat" // 随机决定：「保持这两个子字符串的顺序不变」
"gr/eat" --> "g/r / e/at" // 在子字符串上递归执行此算法。两个子字符串分别在随机下标处进行一轮分割
"g/r / e/at" --> "r/g / e/at" // 随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
"r/g / e/at" --> "r/g / e/ a/t" // 继续递归执行此算法，将 "at" 分割得到 "a/t"
"r/g / e/ a/t" --> "r/g / e/ a/t" // 随机决定：「保持这两个子字符串的顺序不变」
算法终止，结果字符串和 s2 相同，都是 "rgeat"
这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1 的扰乱字符串，返回 true




 思路：分治，一个长的区间分成两个小区间，只要他们能相互交换，那么大区间就能相互交换
 区间动态规划，形式是dp[i][j] = xxx
 这还是三维的区间动规


 *
 * */