//
// Created by lenovo on 2021/3/17.
//

class Solution {
public:
    int numDistinct(string s, string t) {
        int tsize = t.size();
        int ssize = s.size();
        vector<vector<int>> dp(tsize + 1,vector<int>(ssize + 1,0));
        for(int i = 0; i <= ssize; i++)
        {
            dp[0][i] = 1;
            printf("%d ",dp[0][i]);
        }
        printf("\n");
        for(int i = 1 ; i <= tsize; i++)
        {
            printf("%d ", 0);
            for(int j = 1; j <= ssize; j++)
            {
                if(s[j-1] == t[i-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
                else dp[i][j] = dp[i][j-1];
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }
        return dp[tsize][ssize];

    }
};

/**
/*
 *
 *
 *
给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。

 

示例 1：

输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)
rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^

思路：就是两个字符串，然后普通的动规
 *
 * **/