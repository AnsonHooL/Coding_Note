//
// Created by lenovo on 2021/3/13.
//

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = 1;
        int minp = 1;
        int maxre = INT32_MIN;
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            if(nums[i] < 0) swap(maxp,minp);
            maxp = max(maxp * nums[i], nums[i]);
            minp = min(minp * nums[i], nums[i]);
            maxre = max(maxre, maxp);
        }
        return maxre;
    }
};
/**
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

思路：这题有点像打家劫舍，就是乘还是不乘，但是难点在于，求最大值，
 同时维护了一个最大值和最小值，这样就牛逼了，最小值乘以负数就变成了最大值，而最大值遇到负数就不行了，此时最大值就变成了负数，相当于断开了一样
 太牛了，
 很巧妙但是思路是对的
 
 *
 * */