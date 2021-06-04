//
// Created by lenovo on 2021/4/7.
//

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;

            if(nums[low] > nums[mid]) ///后面有序
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
                if(nums[mid] > target && nums[low] <= target)
                {
                    high = mid - 1;
                } else
                {
                    low = mid + 1;
                }
            }else ///这个也很关键，很细节
            {
                low++;
            }
        }
        return -1;

    }
};
/***
 * 思路:
 * 传统二分就是通过和中间的比较就行了
 * 这题就是要分成两个序列，前面一个序列，后面一个序列。
 * 一个是有序一个是无序，然后通过和有序那部分进行比较来判断，减少那一部分的区间,如果在有序区间则，减去无序，如果不在则减去有序
 *
 *
 *
 * /