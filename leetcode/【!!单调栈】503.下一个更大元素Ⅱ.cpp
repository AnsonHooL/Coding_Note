//
// Created by lenovo on 2021/3/6.
//

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> mystack;
        int size = nums.size();

        for(int i = 0; i < size; i++) ///巧妙的双倍数组
        {
            nums.push_back(nums[i]);
        }

        vector<int> re(size);

        for(int i = 0; i < size * 2; i++)
        {
//            if(mystack.size() == 0 || nums[i] < mystack.top())
//            {
//                mystack.push(i);
//            }
            while(!mystack.empty() && nums[mystack.top()] < nums[i])
            {
                int index = mystack.top();
                if(index < size) re[index] = nums[i];
                mystack.pop();
            }
            mystack.push(i);
        }
        while(!mystack.empty())
        {
            int index = mystack.top();
            mystack.pop();
            if(index < size) re[index] = -1;
        }
        return re;
    }
};
/**
 * 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:

输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数；
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。

思路：单调栈啊单调栈，最关键的是弹出机制，就是什么时候该弹出，这道题里
 比栈里大的就全弹出来，然后就是他的下一个最大值，到最后如果，栈里没弹出来的就说明是，没有最大值的，那么就是要输出-1；
 * */