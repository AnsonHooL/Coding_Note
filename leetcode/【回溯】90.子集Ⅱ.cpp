//
// Created by lenovo on 2021/3/31.
//

class Solution {
public:
    vector<vector<int>>  re;
    vector<vector<int>> subsetsWithDup(vector<int> nums) {
        vector<int> path;
        sort(nums.begin(),nums.end());
        backtrace(nums,path,0);
        return re;
    }
    void backtrace(vector<int>& nums, vector<int>& path, int depth)
    {
        if(depth == nums.size())
        {
            re.push_back(path);
            return;
        }

        int length = 1;

        for(int i = depth + 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[i - 1]) break;
            else length++;
        }

        for(int i = 0; i <= length; i++)
        {
            for(int j = 0; j < i; j++)
                path.push_back(nums[depth]);

            backtrace(nums,path, depth + length);

            for(int j = 0; j < i; j++)
                path.pop_back();
        }

    }
};
/**
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

思路：看怎么有更优的思路，感觉不太行
 *
 * */