//
// Created by lenovo on 2020/12/14.
//

class Solution {
public:
    int countDigitOne(int n) {
        string num = to_string(n);
        int high = n / 10;
        long cur = 1;
        int sum = 0;
        int low = 0;
        for(int i = num.size() -1; i >= 0; i--)
        {
            int digt = num[i] - '0';
            if(digt == 0)
            {
                sum += high * cur;
            } else if(digt == 1)
            {
                sum += high * cur + low + 1;
            } else{
                sum += (high+1) * cur;
            }
            high = high / 10;
            low = low + digt*cur;
            cur = cur * 10;
        }
        return sum;
    }
};

/**
 *
 *
 *
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。



示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6

 *
 * */

/// 思路：数学法 数字是 4107，则统计由高到低每一位的数字出现的1的此时
/// 看数字0位： 4107： 00 1 0 ~ 40 1 9： 000 ~ 409 = 41 * cur，只与高位相关，还要乘10（0所在的位置）
/// 看数字1位： 4107： 0100 ~ 4107 ： 0 00~4 07 = 4*100 + 7 +1与高低位都相关
/// 看数组2~9位：数字7位： 4107： 0001~4101 ： 000~410：（410+1）*cur

















