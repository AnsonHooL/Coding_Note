//
// Created by lenovo on 2021/6/8.
//

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int low = 0;
        for(auto& num : nums){
            if(num != 0) nums[low++] = num;
        }
        int s = nums.size();
        for(; low < s; low++){
            nums[low] = 0;
        }
    }
};

/**
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]


 * */