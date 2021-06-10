//
// Created by lenovo on 2021/6/10.
//
///思路；就是数学题啊，从前往后，如果一直升序就没事，如果降序，那么就找到降序的最小值，然后确定他的位置就能确定排序的左边界
///画图就知道了，插入排序的思想
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minnum = INT32_MAX, maxnum = INT32_MIN;
        bool flag = false;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1])
                flag = true;
            if(flag)
                minnum = min(minnum, nums[i]);
        }
        flag = false;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] > nums[i+1])
                flag = true;
            if(flag)
                maxnum = max(maxnum, nums[i]);
        }
        int left, right;
        for(left = 0; left < nums.size(); left++){
            if(minnum < nums[left])
                break;
        }
        for (right = nums.size() - 1; right >= 0; right--) {
            if (maxnum > nums[right])
                break;
        }
        return right - left < 0 ? 0 : right - left + 1;


    }
};

/**
 * 给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

请你找出符合题意的 最短 子数组，并输出它的长度。

 

示例 1：

输入：nums = [2,6,4,8,10,9,15]
输出：5
解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
示例 2：

输入：nums = [1,2,3,4]
输出：0


 *
 * */