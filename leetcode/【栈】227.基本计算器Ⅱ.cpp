//
// Created by lenovo on 2021/6/7.
//

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
 *  没有括号，只有加减乘除
 *  这个只用vector做就行了，不用栈，而且，正数和负数只需要简单的将符号保存一下就行，很方便，简单
 *
 *
 * */