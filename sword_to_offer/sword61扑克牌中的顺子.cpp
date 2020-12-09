//
// Created by lenovo on 2020/12/8.
//

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int zero = 0;
        int diff = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                zero++;
                continue;
            }
            if(i>0 && nums[i-1]!=0 && nums[i-1]!=nums[i])
            {
                diff += nums[i]  - nums[i-1] -1;
            } else if(i>0 && nums[i-1]!=0 && nums[i-1]==nums[i])
            {
                return false;
            }
        }
        return zero>=diff; /**0 0 0 9 11 这种防备一下**/
    }
};

/**
 *
 *
 * 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

示例 1:

输入: [1,2,3,4,5]
输出: True
 

示例 2:

输入: [0,0,1,2,5]
输出: True

思路：计算出牌组的空隙，看大王小王能不能填补空隙
 *
 *
 * */
