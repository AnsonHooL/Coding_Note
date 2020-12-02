//
// Created by lenovo on 2020/11/30.
//

class Solution {
public:
    //11-25
    int translateNum(int num) {
        string numstr = to_string(num);
        if(numstr.size() == 1)
            return 1;
        if(numstr.size() == 2)
        {
            if(num <= 25 && num>=10) return 2;
            else return 1;
        }
        int dp[33] ={0};
        dp[0] = 1;
        int r = 1;
        dp[1] = 1;
        int i;
        for(i = 2;i<=numstr.size();i++)
        {
            int plus = (numstr[i-2] - '0') * 10 + (numstr[i-1] - '0');
            if(plus <= 25 && plus >=10)
                r += dp[i-2];
            dp[i] = r;
        }
        return dp[i-1];
    }
};

/***
 * 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
 * 一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"


 思路：用动态规划来做，很简单，还可以优化下空间
*/


