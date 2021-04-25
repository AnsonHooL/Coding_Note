//
// Created by lenovo on 2021/4/24.
//

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        int amount = nums.size();
        for(int j = 0; j <= target; j++){ //遍历背包
            for(int i = 0; i < amount; i++){ //遍历物品
                if(j - nums[i] >= 0 && dp[j] < INT_MAX - dp[j - nums[i]]) dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};

/**
 * 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

 

示例 1：

输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。

思路：
 这种就是背包题的变种，target就是背包大小。数字就是物品，可以拿无数次，所以就是完全背包
 组合：先遍历物品，再遍历背包
 排列：先遍历背包，再遍历物品

 * */