//
// Created by lenovo on 2021/3/28.
//

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        int dup = 0;
        vector<int> re;
        for(int i = 0; i < size; i++)
        {
            int number = abs(nums[i]);
            if(nums[number - 1] < 0) dup = number;
            else
            {
                nums[number - 1] = -nums[number - 1];
            }
        }
        for(int i = 0; i < size; i++)
        {
            if(nums[i] > 0)
                re.push_back(i+1);
        }

        return re;

    }
};
/**
 * 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]

 *
 * */