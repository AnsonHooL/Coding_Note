//
// Created by lenovo on 2021/4/17.
//

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> S;
        for(int i = 0; i < nums.size(); i++)
        {

            auto iter = S.lower_bound( max(nums[i], INT_MIN + t) - t);
            if(iter != S.end() && *iter <= min(nums[i], INT_MAX - t) + t)
                return true;

            S.insert(nums[i]);
            if(i >= k) S.erase(nums[i - k]);
        }
        return false;
    }
};

/**
 *
 * 给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。

如果存在则返回 true，不存在返回 false。

 

示例 1：

输入：nums = [1,2,3,1], k = 3, t = 0
输出：true
示例 2：

输入：nums = [1,0,1,1], k = 1, t = 2
输出：true
示例 3：

输入：nums = [1,5,9,1,5,9], k = 2, t = 3
输出：false


 思路：维护区间的有序集合，zset，然后，找到[x-t,x+t]区间的数即可
 *
 * */