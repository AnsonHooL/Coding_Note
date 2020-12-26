//
// Created by lenovo on 2020/12/24.
//

///最长上升子序列
/***
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
*/


/// 动态规划方法1
/// 方程是dp[i] = 以第i个数字结尾的上升子序列,的最长上升子序列长度是多少
/// 因此dp[i]  = max(dp[k]) + 1, k = 0~i-1 ， 满足第 小于 第i个数字，且dp[k] 最大
/// 因此时间复杂度是O（n * n）
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int gmax = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            int j = i;
            int num = nums[i];
            int maxdp = 1; ///长度至少为1
            while (--j >= 0)
            {
                if(num > nums[j])
                {
                    maxdp = max(dp[j] + 1, maxdp); ///选出最大的
                } else
                {
//                    maxdp = max(dp[j], maxdp);
                }
            }
            dp[i] = maxdp;
            gmax = max(maxdp, gmax);
        }
        return gmax;
    }
};




/// 贪心方法, 动态规划 + 二分
/// 上面的方法，每次都要暴力遍历所有dp，下面是贪心 + 动规 + 二分的做法？
/// dp[i] = 长度为 i + 1 的 最长上升子序列的 “最小” 结束数字，例如 1 7 2 3
///  dp = 【1 ， 2 ， 3】 ，长度为 2 的最长上升子序列的 最小 结尾是 2
/// 这样dp[i]就是个有序序列，那么以后的每一个数字k就是做一个插入操作（这里就可以二分，不做二分也大大减少了操作），找到合适的位置放进去
/// dp[i] < k < dp[i+1], 每个数字进来都有用

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return 1;

        vector<int> dp(nums.size() + 10, 0);
        dp[0] = nums[0];
        int gmax = 1;
        int pos = 0;

        for(int i = 1; i < nums.size(); i++)
        {
            int num  = nums[i];
            int j = pos;
            while(j >= 0)
            {
                if(num > dp[j])
                {
                    if(dp[j+1] == 0 || dp[j+1] > num) ///num大于所有数字
                    {
                        dp[j+1] = num;
                        if(j+1 > pos) pos++;
                    }
                    break;
                }
                if(j == 0)
                    dp[j] = num;
                j--;
            }
        }
        return pos + 1;
    }
};





