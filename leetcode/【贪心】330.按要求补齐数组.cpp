//
// Created by lenovo on 2020/12/29.
//


/**
 *
 * 给定一个已排序的正整数数组 nums，和一个正整数 n 。从 [1, n] 区间内选取任意个数字补充到 nums 中，使得 [1, n] 区间内的任何数字都可以用 nums 中某几个数字的和来表示。请输出满足上述要求的最少需要补充的数字个数。

示例 1:

输入: nums = [1,3], n = 6
输出: 1
解释:
根据 nums 里现有的组合 [1], [3], [1,3]，可以得出 1, 3, 4。
现在如果我们将 2 添加到 nums 中， 组合变为: [1], [2], [3], [1,3], [2,3], [1,2,3]。
其和可以表示数字 1, 2, 3, 4, 5, 6，能够覆盖 [1, 6] 区间里所有的数。
所以我们最少需要添加一个数字。


 思路：贪心
 当前nums是排序的，一个个加入进来，假设当前能表示的范围是 [1, total],那么加入一个K后其表示范围为：
 ///[1,total] + k  -> [1,total] U [k, total + k]
 /// 如果total + 1 < k --》 total < K - 1, 则要插入一个 total + 1，就是total和k之前需要插入一个值，否则中间有几个数表达不出来
 * */



class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long total = 0;
        int index = 0;
        int count = 0;
        while (total < n)
        {
            if(index < nums.size() && total >= nums[index] -1)
            {
                total += nums[index];
                index++;
            } else{
                count++;
                total = total * 2 + 1;
            }
        }
        return count;
    }
};