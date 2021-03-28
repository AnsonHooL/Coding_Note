//
// Created by lenovo on 2021/3/16.
//

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primevec(n + 1, true);
        for(int i = 2; i <= n; i++)
        {
            if(primevec[i])
            {
                for(int j = i; j  <= n / i; j++) ///这是优化过的，j 从 i 开始 计数，素数筛
                {
                    primevec[j * i] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++)
        {
            if(primevec[i]) count++;
        }
        return count;
    }
};

/**
 *
统计所有小于非负整数 n 的质数的数量。



示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

 思路：素数筛 加一个 优化，跳过


 *
 * */