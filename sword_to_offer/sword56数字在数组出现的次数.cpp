//
// Created by lenovo on 2020/12/3.
//

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int result = 0;
        for(auto x : nums)
        {
            result ^= x;
        }
        uint mask = 0x1L;
        while(!(mask & result))
        {
            mask <<= 1;
        }
        int left  = 0;
        int right = 0;
        for(auto x : nums)
        {
            if(x & mask) left^=x;
            else right^=x;
        }
        vector<int> rec;
        rec.push_back(left);
        rec.push_back(right);
        return rec;
    }
};

/****
 *
 *
 *
 *一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

 

示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]

思路：先异或然后分组。

 *
 *
 *
 *
 *
 *
 *
 *
 * /