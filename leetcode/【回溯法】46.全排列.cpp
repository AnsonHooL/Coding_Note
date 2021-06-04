//
// Created by lenovo on 2021/6/3.
//

class Solution {
public:

    vector<vector<int>> result;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> path;
        backtrace(nums, path, used);
        return result;
    }

    void backtrace(vector<int>& nums, vector<int>& path, vector<bool>& used){

        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true){
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;

            backtrace(nums, path, used);

            path.pop_back();
            used[i] = false;

        }

    }
};

/**
 *给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]

思路：
 so easy 哇

 * */