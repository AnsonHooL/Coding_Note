//
// Created by lenovo on 2021/4/15.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(
                dorob(vector<int>{nums.begin(),nums.end() - 1}),
                dorob(vector<int>{nums.begin() + 1,nums.end()})
        );

    }
    int dorob(vector<int> nums)
    {
        int s = nums.size();
        vector<int> dp0(s+1,0);
        vector<int> dp1(s+1,0);
        for(int i = 1; i <= s; i++)
        {
            dp0[i] = max(dp0[i-1], dp1[i-1]);
            dp1[i] = max(dp1[i-1], dp0[i-1] + nums[i-1]);
        }

        return dp1[s];

    }
};
/**
 *
 *你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。


 *
 *
 *
 *
 *
 *
 *
 * */