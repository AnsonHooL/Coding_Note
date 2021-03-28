//
// Created by lenovo on 2021/3/16.
//

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        int dup = 0;
        int err = 0;
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
            if(nums[i] > 0) err = i + 1;
        }

        return {dup, err};

    }
};

/**
 * 集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。

给定一个数组 nums 代表了集合 S 发生错误后的结果。

请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

 

示例 1：

输入：nums = [1,2,2,4]
输出：[2,3]

 思路：原地哈希，加判断唯一一个正数索引就是miss的元素
 * */