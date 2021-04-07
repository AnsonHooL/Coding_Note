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