//
// Created by lenovo on 2021/4/7.
//

class Solution {
public:
    bool search(vector<int> nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target) return true;

            if(nums[low] == nums[mid])
            {
                low++;
                continue;
            } else if(nums[low] > nums[mid]) ///后面有序
            {
                if(nums[mid] < target && nums[high] >= target) ///在后面
                {
                    low = mid + 1;
                } else
                {
                    high = mid - 1;
                }
                continue;
            } else if(nums[low] < nums[mid]) ///前面有序
            {
                if(nums[mid] > target && nums[low] <= target) //这里要小于等于
                {
                    high = mid - 1;
                } else
                {
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};

/**
 * 已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。

给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。

 

示例 1：

输入：nums = [2,5,6,0,0,1,2], target = 0
输出：true


 ///67 12345 后面有序
///34567 12 前面有序
///111101 分不清哪个有序，就low++，跳过
///101111

 * */