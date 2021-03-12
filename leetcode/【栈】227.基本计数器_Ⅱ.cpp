//
// Created by lenovo on 2021/3/11.
//

///妙啊，用一个变量op代替了符号栈
///

class Solution {
public:
    int calculate(string s) {
        vector<int> v;
        long num = 0;
        char op = '+';
        int n = s.size();

        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i])) num = num*10 + s[i] - '0';
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i==n-1)
            {
                if(op == '+')v.push_back(num);
                else if(op == '-')v.push_back(-num);
                else if(op == '*')v.back() *= num;
                else if(op == '/')v.back() /= num;
                op = s[i];
                num = 0;
            }
        }
        int res = 0;
        for(auto& a:v)
        {
            res += a;
        }
        return res;
    }
};


/**
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

整数除法仅保留整数部分。

 

示例 1：

输入：s = "3+2*2"
输出：7
示例 2：

输入：s = " 3/2 "
输出：1
示例 3：

输入：s = " 3+5 / 2 "
输出：5


 *
 * */