//
// Created by lenovo on 2021/3/10.
//

class Solution {
public:
    void func(stack<char>& symbolstack, stack<int>& numberstack) ///退栈，然后做运算的函数
    {
        int n2 = numberstack.top();
        numberstack.pop();
        int n1;
        if(numberstack.empty()) n1 = 0;
        else
        {
            n1 = numberstack.top();
            numberstack.pop();
        }
        if(symbolstack.top() == '+')
        {
            symbolstack.pop();
            numberstack.push(n1 + n2);
        } else if(symbolstack.top() == '-')
        {
            symbolstack.pop();
            numberstack.push(n1 - n2);
        }
    }

    int calculate(string s) {
        stack<char> symbolstack;
        stack<int> numberstack;
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(c == ' ')
                continue;
            else if(c <= '9' && c >= '0')
            {
                int number = c - '0';
                while(s[i+1] <= '9' && s[i+1] >= '0')
                {
                    number = number * 10 + (s[i+1] - '0');
                    i++;
                }
                numberstack.push(number);
            }
            else if(c == '+' || c == '-')
            {
                while(!symbolstack.empty() && (symbolstack.top() == '+' || symbolstack.top() == '-'))
                {
                    func(symbolstack, numberstack);
                }
                symbolstack.push(c);
            }
            else if(c == '(')
            {
                symbolstack.push(c);
            }
            else if(c == ')')
            {
                while(symbolstack.top() != '(')
                {
                    func(symbolstack, numberstack);
                }
                symbolstack.pop();
            }
        }
        while(!symbolstack.empty())
        {
            func(symbolstack, numberstack);
        }
        return numberstack.top();
    }
};

/**
 * 实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。

 

示例 1：

输入：s = "1 + 1"
输出：2
示例 2：

输入：s = " 2-1 + 2 "
输出：3
示例 3：

输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23


 *
 * */