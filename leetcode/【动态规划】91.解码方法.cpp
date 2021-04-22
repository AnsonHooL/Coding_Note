//
// Created by lenovo on 2021/4/21.
//

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), 0);
        if(s[0] == '0') return 0;
        else dp[0] = 1;

        for(int i = 1; i< s.size();i++)
        {
            if(s[i] == '0' && !(s[i-1] == '1' || s[i-1] == '2'))
            {
                return 0;

            } else {
                if(s[i] == '0') {
                    dp[i] = (i >= 2 ? dp[i-2]: 1);
                } else {
                    int num = (s[i-1] - '0')*10 + s[i] - '0';
                    if(num<=26 && num >= 10)
                    {
                        dp[i] = (i >= 2 ? dp[i-2] + dp[i-1]: dp[i-1] + 1);

                    } else{

                        dp[i] =  dp[i-1] ;

                    }

                }
            }
        }

        return dp[s.size()-1];
    }
};

/**
 *
 *
 *
 *
 *一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：

'A' -> 1
'B' -> 2
...
'Z' -> 26
要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：

"AAJF" ，将消息分组为 (1 1 10 6)
"KJF" ，将消息分组为 (11 10 6)
注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。

给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。

题目数据保证答案肯定是一个 32 位 的整数。




思路：非常基础的动规，就是稍微要注意细节
 *
 *
 *
 *
 *
 *
 * */