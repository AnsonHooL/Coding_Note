//
// Created by lenovo on 2020/11/27.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int maxlast = max;
        for(int i=1; i<nums.size();i++)
        {
            int maxi = (maxlast + nums[i] > nums[i]) ? maxlast + nums[i] : nums[i];
            if(maxi > max) max = maxi;
            maxlast = maxi;
        }
        return max;
    }
};

/***
 * 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组中和的最大值。
 *
 * 要求时间复杂度为O(n)。
 *
 * 动态规划，能构成dp方程的是，dp[i]为每个pos == i结束的子数组的最大值，与下一个连续判断是否能构成最大值
 *
 *
 *
 * */