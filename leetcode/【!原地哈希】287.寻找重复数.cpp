//
// Created by lenovo on 2021/3/13.
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            int number = abs(nums[i]);
            if(nums[number - 1] < 0) return true;
            else
            {
                nums[number - 1] = -nums[number - 1];
            }
        }
        return -1;
    }
};

/**
 * 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。

思路一：原地哈希，哈希到某个地方后，不是真的放，只是做标记
 思路二：有一个重复的话，不就是可以当成一个环形链表，当场快慢指针，找环的入口吗：
 数学公式是：a + nb 一定能在入口碰到，而快慢指针相遇，快指针必然多走了nb
 所以先让一个指针走nb，在和一个指针一起从入口逐步移动，必然能在入口相遇
 *
 *
 *
 * */