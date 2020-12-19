/// 思路一用哈希
int findRepeatNumber(vector<int>& nums) {
    unordered_map<int,int> map;
    for(auto a : nums)
    {
        auto iter = map.find(a);
        if(iter != map.end())
        {
            return a;
        }
        else
        {
            map[a] = 1;
        }
    }

}

///思路二，原地swap，直到发现位置已经有了一个合适的数字
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++)
        {
            while(nums[i] != i)
            {
                int tmp = nums[i];
                if(nums[tmp] == tmp) return tmp;
                else swap(nums[tmp],nums[i]);
            }
        }
        return 0;
    }
};

/***
 *
 * 找出数组
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3
 *
 * /
