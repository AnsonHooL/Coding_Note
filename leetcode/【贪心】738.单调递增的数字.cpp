//
// Created by lenovo on 2020/12/15.
//

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string num = to_string(N);
        // for(int i = 0;i < num.size()-1;i++)
        // {
        //     if(num[i] > num[i+1])
        //     {
        //         num[i] -= 1;
        //         for(int j = i+1; j < num.size(); j++)
        //         {
        //             num[j] = '9';
        //         }
        //         for(int j = i; j > 0; j--)
        //         {
        //             if(num[j] < num[j-1])
        //             {
        //                 num[j] = '9';
        //                 num[j-1] -= 1;
        //             }
        //         }
        //         break;
        //     }
        // }
        for(int i = num.size()-1;i > 0; i--)
        {
            if(num[i] < num[i-1])
            {
                for(int j = i; j < num.size(); j++)
                {
                    num[j] = '9';
                }
                num[i-1] -=1;
            }
        }
        long cur = 1;
        int sum = 0;
        for(int i = num.size()-1; i >= 0; i--,cur*=10)
        {
            sum += (num[i] - '0') * cur;
        }
        return sum;
    }
};

/***
 *给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:

输入: N = 10
输出: 9
示例 2:

输入: N = 1234
输出: 1234
示例 3:

输入: N = 332
输出: 299

思路：贪心的从后往前扫描，遇到逆序的则，后面的全变成9就完事了
 * /