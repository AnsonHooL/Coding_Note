//
// Created by lenovo on 2020/12/14.
//


///动态规划，都是从后往前
///pattern串从后往前，三种情况是 * . char
///1（. or char）：若那么只需要当前位置匹配，f[i][j] = f[i-1][j-1]
///2.1(* 0位 或 n位) 若不使用*号，则pattern串退两位 主串不动，f[i][j] = f[i][j-2]
///2.2（* 0位 或 n位） 若使用*号，pattern 不动 主串退一格，f[i][j] = f[i-1][j]

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        bool dp[n+1][m+1];
        for(int i = 0;i<=n;i++)
        {
            for(int j = 0;j<=m;j++)
            {
                dp[i][j] = false; ///若空的模板串 j==0，非空的主串，必为false
            }
        }
        dp[0][0] = true;

        for(int i = 0; i <= n;i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(p[j-1] != '*' && p[j-1] != '.') ///模式串为字符
                {
                    if(i>0 && s[i-1] == p[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1];
                    } else dp[i][j] = false;
                }else if(p[j-1] == '.')
                {
                    if(i>0)
                    {
                        dp[i][j] = dp[i-1][j-1];
                    } else dp[i][j] = false;
                } else if(p[j-1] == '*')
                {
                    ///不看*
                    if(j>=2)
                    {
                        dp[i][j] |= dp[i][j-2];
                    }
                    ///看*
                    if(j>=2 && i>=1 &&( p[j-1-1] == '.' || p[j-1-1] == s[i-1])  )
                    {
                        dp[i][j] |= dp[i-1][j];
                    }
                }
            }

        }

        return dp[n][m];
    }
};

/***
 *请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。


///动态规划，都是从后往前
///pattern串从后往前，三种情况是 * . char
///1（. or char）：若那么只需要当前位置匹配，f[i][j] = f[i-1][j-1]
///2.1(* 0位 或 n位) 若不使用*号，则pattern串退两位 主串不动，f[i][j] = f[i][j-2]
///2.2（* 0位 或 n位） 若使用*号，pattern 不动 主串退一格，f[i][j] = f[i-1][j]


 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * /