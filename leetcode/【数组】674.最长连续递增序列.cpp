//
// Created by lenovo on 2021/1/24.
//

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int low = 0;
        int high = 0;
        int maxre = 0;
        while(high < nums.size())
        {
            if(low == high || nums[high] > nums[high - 1])
                high++;
            else
            {
                maxre = max(maxre, high - low);
                low = high;
            }
        }
        maxre = max(maxre, high - low);
        return maxre;
    }
};

/**
 *
 * 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

 

示例 1：

输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。


 思路：双指针
 * */