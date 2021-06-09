//
// Created by lenovo on 2021/6/9.
//

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) sum += num;

        if(sum % 2 == 1) return false;

        sum = sum / 2;

        vector<int> dp(sum + 1, 0);
        ///背包大小为 sum， 物品是 num， 0 1背包
        for(int i = 0; i < nums.size(); i++){

            ///注意这里方向是反的
            for(int j = sum; j > 0; j--){

                if(j >= nums[i]){

                    dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);

                }

            }
        }

        cout<< dp[sum] <<endl;
        return dp[sum] == sum;
    }
};
/***
 *
 *
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。



示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。

 *
 *
 * /