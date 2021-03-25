//
// Created by lenovo on 2021/3/24.
//

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int two = INT_MIN;
        // 保存3的单调栈，从底到顶递减
        stack<int> s;
        int n = nums.size();
        for (int i = n-1; i >=0; --i)
        {
            // 找到比2小的数字，那么满足条件
            if (nums[i] >= two)
            {
                // 如果发现大于栈顶（破坏了单调性），那么要去更新栈和two的数值（two变为更大的数字）
                while (!s.empty() && nums[s.top()] < nums[i])
                {
                    two = nums[s.top()];
                    s.pop();
                }

                s.push(i);
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

/**
 * 给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。

注意：n 的值小于15000。

示例1:

输入: [1, 2, 3, 4]

输出: False

解释: 序列中不存在132模式的子序列。


 *
 * */


///思路非常巧妙，从后往前的单调栈，先找到最大的3 2 那么只要判断 1比2小就行了。