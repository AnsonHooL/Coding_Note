//
// Created by lenovo on 2020/12/2.
//

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low  = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) >>1;
            if(nums[mid] == target)
            {
                low = mid;
                break;
            } else if(nums[mid] > target)
            {
                high = mid - 1;
            } else
            {
                low = mid +1;
            }
        }

        if(low > high)
            return 0;

        int count = 1;
        int tmp = low - 1;
        while (tmp >= 0 &&nums[tmp] == target ) //不要越界
        {
            count++;
            tmp--;
        }
        tmp = low + 1;
        while ( tmp <= nums.size() -1&& nums[tmp] == target) //不要越界
        {
            count++;
            tmp++;
        }
        return count;
    }
};

/**
 *示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2


 思路：二分法，不要越界
 *
 *
 * /