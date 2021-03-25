//
// Created by lenovo on 2021/3/23.
//
///思路一： 用的2的多少次幂做动规
class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) return {0};
        vector<int> dp(num + 1,0);
        dp[0] = 0;
        dp[1] = 1;
        int point = 1;
        for(int i = 2; i <= num; i++)
        {
            if(i == point*2) ///这里判断2的多少次幂 可以直接（i-1） & i == 0 啊，太骚了
            {
                dp[i] = 1;
                point *= 2;
            } else
            {
                dp[i] = dp[i - point] + 1;
            }
        }
        return dp;
    }
};


///思路二：用奇偶性做动规，奇数比偶数多一，偶数 = 右移一个0
vector<int> countBits(int num) {
    vector<int> result(num+1);
    result[0] = 0;
    for(int i = 1; i <= num; i++)
    {
        if(i % 2 == 1)
        {
            result[i] = result[i-1] + 1;
        }
        else
        {
            result[i] = result[i/2];
        }
    }

    return result;
}
///思路三：消掉最后的一个1，
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for (int i = 1; i <= num; i++) {
            bits[i] = bits[i & (i - 1)] + 1;
        }
        return bits;
    }
};




/**
 * 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]
示例 2:

输入: 5
输出: [0,1,1,2,1,2]


 *
 * */