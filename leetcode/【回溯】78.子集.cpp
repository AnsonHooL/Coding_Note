//
// Created by lenovo on 2021/3/31.
//


class Solution {
public:
    vector<vector<int>>  re;
    vector<vector<int>> subsets(vector<int> nums) {
        vector<int> path;
        sort(nums.begin(),nums.end());
        backtrace(nums,path,0);
        return re;
    }
    void backtrace(vector<int>& nums, vector<int>& path, int depth) {

        if (depth == nums.size()) {
            re.push_back(path);
            return;
        }

        if (depth == 0 || (depth > 0 && nums[depth] != nums[depth - 1])) {
            path.push_back(nums[depth]);
            backtrace(nums, path, depth + 1);
            path.pop_back();
        }

        backtrace(nums, path, depth + 1);
    }
};

///学完代码随想录的解法，思路清晰多了！不再莽夫

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtarace(path, 0, nums);
        return result;
    }

    void backtarace(vector<int>& path, int startindex, vector<int>& nums){

        result.push_back(path);

        for(int i = startindex; i < nums.size(); i++){

            path.push_back(nums[i]);

            backtarace(path,i + 1,nums);

            path.pop_back();

        }
    }
};

/**
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


 *
 * */