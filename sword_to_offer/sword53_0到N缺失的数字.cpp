//
// Created by lenovo on 2020/12/2.
//

#include <iostream>




class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int low  = 0;
        int high = nums.size() -1;
        int mid = 0;
        while(low < high)
        {
            mid = (low + high) >> 1;
            if(nums[mid] == mid)
            {
                low = mid + 1;
            } else if(nums[mid] > mid)
            {
                high = mid -1;
            }
        }
        if(nums[low] == low) return low + 1;
        else return nums[low] - 1;
    }
};

/*
 思路：二分法
 *
 *
 * 输入: [0,1,3]
输出: 2
 * *
 *
 */