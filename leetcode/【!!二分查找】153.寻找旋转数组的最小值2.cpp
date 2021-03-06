//
// Created by lenovo on 2021/4/8.
//

class Solution {
public:
    int findMin(vector<int> nums) {
        if(nums.size() == 1) return nums[0];
        int low  = 0;
        int high = nums.size() - 1;
        while(low < high)
        {
            int mid = (low + high )/ 2;
            if(nums[mid] < nums[high]) high = mid;
            else if(nums[mid] > nums[high]) low = mid + 1;
            else if(nums[mid] == nums[high])
            {
                high--;
            }
        }
        return nums[low];
    }
};

/**
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

输入: [1,3,5]
输出: 1
示例 2：

输入: [2,2,2,0,1]
输出: 0


 二分查找，不是和high比较就是和数组的最后一位，切记

 *
 *
 * */