//
// Created by lenovo on 2021/4/8.
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return vector<vector<int>> {};

        sort(nums.begin(),nums.end());

        vector<vector<int>> re;

        for(int i = 0 ; i < nums.size() - 2; )
        {
            if(nums[i] > 0) break;
            int low  = i + 1;
            int high = nums.size() -1;
            while(low < high)
            {
                if(nums[i] + nums[low] + nums[high] == 0)
                {
                    re.push_back(vector<int> {nums[i] , nums[low] , nums[high]});
                    low++;
                    while(low < nums.size() && nums[low] == nums[low - 1])
                    {
                        low++;
                    }

                    high--;
                    while (high >= 0 && nums[high] == nums[high + 1])
                    {
                        high--;
                    }
                } else if(nums[i] + nums[low] + nums[high] < 0)
                {
                    low++;
                }else if(nums[i] + nums[low] + nums[high] > 0)
                {
                    high--;
                }
            }
            i++;
            while (i < nums.size() && nums[i] == nums[i -1])
            {
                i++;
            }
        }
        return re;
    }
};

/**
 *给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]


 思路：
 先排好序，然后因为不能重复，所以 ***=***=**=***，只要遍历第一个数“=”，然后在其后面去寻找第二第三个数即可，
 1.注意跳过重复数子，第一个数字需要跳过
 2.然后双指针找三数之和，找到了也要跳过。
 3.因为排好序，所以大于0的数可以跳过了

 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */