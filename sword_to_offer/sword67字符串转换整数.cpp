//
// Created by lenovo on 2020/12/10.
//

class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        long res = 0;
        bool negative = false;
        while(str[i] == ' ')
            i++;
        if(str[i]!='+' && str[i]!='-' && !isdigit(str[i]))
            return 0;
        if(str[i] == '-')
            negative = true;
        if(str[i] == '+' || '-' == str[i])
            i++;
        while (isdigit(str[i]) && str[i])
        {
            res = res*10 + (str[i] - '0');
            if(res>INT32_MAX && !negative) return INT32_MAX;
            if(-res < INT32_MIN) return INT32_MIN;
            i++;
        }
        return negative ? -res : res;
    }
};

///不用long版本
class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        int res = 0;
        bool negative = false;
        while(str[i] == ' ')
            i++;
        if(str[i]!='+' && str[i]!='-' && !isdigit(str[i]))
            return 0;
        if(str[i] == '-')
            negative = true;
        if(str[i] == '+' || '-' == str[i])
            i++;
        while (isdigit(str[i]) && str[i])
        {
            ///res * 10 + str[i]- '0' > INT32_MAX越界
            if(res  > (INT32_MAX - (str[i] - '0')) / 10 )
            {
                if(negative) return INT32_MIN;
                else return INT32_MAX;
            }
            res = res*10 + (str[i] - '0') ;
            i++;
        }
        return negative ? -res : res;
    }
};

/***
 *
 *
 *
 * 很常规，但是要注意一些边界，要判断是否为负数，否则返回错误
 * if(res>INT32_MAX && !negative) return INT32_MAX;
            if(-res < INT32_MIN) return INT32_MIN;


 重点：不能用long！！！！！！！！！！！才难
 思路也是不能加，乘溢出，转化为减法和除法

 *
 *
 *
 * /