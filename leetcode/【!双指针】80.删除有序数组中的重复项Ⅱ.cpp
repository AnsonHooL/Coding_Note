//
// Created by lenovo on 2021/4/6.
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

/**




 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

思路：很巧妙，快慢指针。慢指针指向的是新数组，快指针指向的是旧数组，只需要比对，慢指针的后两位与快指针是否相同即可以决定是否放置。
 我觉得和快指针自己判断也行啊。（不行！因为数组已经被改变了，所以没有这样判断）





 **/