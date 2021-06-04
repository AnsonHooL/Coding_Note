//
// Created by lenovo on 2021/6/3.
//

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto less = [](vector<int> lhs, vector<int>rhs){
            return lhs[0] < rhs[0];
        };
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end(), less);

        int low  = intervals[0][0];
        int high = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){

            if(intervals[i][0] <= high){

                high = max(high, intervals[i][1]);

            } else{
                result.push_back({low, high});

                low  = intervals[i][0];
                high = intervals[i][1];

            }
        }

        result.push_back({low, high});
        return result;
    }
};

/**
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

 

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

思路：贪心！
 并且这是按左区间排序的！，所以这个得考虑
 * */