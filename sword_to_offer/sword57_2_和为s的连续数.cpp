//
// Created by lenovo on 2020/12/7.
//

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int low  = 1;
        int high = 1;
        int sum  = 0;
        vector<vector<int>> re;
        while (low <= target/2)
        {
            if(sum < target)
            {
                sum += high;
                high++;

            } else if(sum > target)
            {
                sum -= low;
                low++;
            } else if(sum == target)
            {
                vector<int> tmp;
                for(int i = low; i < high; i++)
                {
                    tmp.push_back(i);
                }
                re.push_back(tmp);
                sum -= low;
                low++;
                sum += high;
                high++;
            }
        }
        return re;
    }
};


/***

输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]

思路：滑动窗口法
维护一个左闭右开的[low.high)的滑动窗口
在窗口内的sum 与 target进行比较，大于小于等于则进行相应的操作




*/