//
// Created by lenovo on 2020/12/8.
//

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> re;
        deque<int> priorque;
        if(nums.size() == 0) return re;
        if(nums.size() <= k)
        {
            sort(nums.begin(),nums.end());
            reverse(nums.begin(),nums.end());
            return vector<int>{nums[0]};
        }
        priorque.push_back(nums[0]);
        int low = 0;
        int high = k;
        for(int i = 1;i<high;i++)
        {
            while(!priorque.empty() && priorque.back() < nums[i]) priorque.pop_back();
            priorque.push_back(nums[i]);
        }
        re.push_back(priorque.front());
        while (high < nums.size())
        {
            if(nums[low] == priorque.front())
            {
                priorque.pop_front();
            }
            if(priorque.empty() || nums[high] > priorque.front()) re.push_back(nums[high]);
            else re.push_back(priorque.front());
            while(!priorque.empty() && priorque.back() < nums[high]) priorque.pop_back();
            priorque.push_back(nums[high]);
            low++;
            high++;
        }
        return re;
    }
};


/****

给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
解释:

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


思路：维护一个 ！！窗口内的单调队列！！
单调队列满足：
1.队列只包含窗口内的值
2.单调递减

窗口每次滑动，进来一个high值，出去一个low值
若low值和单调队列的队首比较，相等则单调队列pop front，说明low是退出的最大值，若不想等，则说明最大值仍在窗口内

进来一个high值，从后往前，将单调队列小于他的值都退出去。这样保证窗口的最大值一直在单调队列就行。就是他退出窗口前，都是
窗口内的最大值


这里的 单调队列 和 优先队列 不一样，仔细体会


/