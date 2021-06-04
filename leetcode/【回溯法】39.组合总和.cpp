//
// Created by lenovo on 2021/6/2.
//

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        backtrace(0, 0, path, used, target, candidates);
        return result;
    }

    void backtrace(int sum, int startindex, vector<int>& path,vector<bool> used, int target, vector<int>& candidates){
        if(sum == target){

            result.push_back(path);

        }

        if(sum > target){
            return;
        }

        for(int i = startindex; i < candidates.size(); i++){

            if(i>0 && (candidates[i] == candidates[i-1] && used[i] == false)){

                continue;

            } else{


                path.push_back(candidates[i]);

                used[i] = true;

                backtrace(sum + candidates[i], i, path, used, target, candidates);

                used[i] = false;
                path.pop_back();

            }

        }

    }

};

/**
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]

思路:

 思考如何去重，还有startindex

 *
 * */