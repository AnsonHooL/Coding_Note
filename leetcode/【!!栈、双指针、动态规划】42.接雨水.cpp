//
// Created by lenovo on 2021/4/2.
//

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lefthigh(height.size(), 0);
        vector<int> righthigh(height.size(), 0);
        for(int i = 1; i < height.size(); i++)
        {
            lefthigh[i] = max(lefthigh[i-1], height[i-1]);
        }
        for(int i = height.size() - 2; i >= 0; i--)
        {
            righthigh[i] = max(righthigh[i+1], height[i+1]);
        }
        int sum = 0;
        for(int i = 0; i < height.size(); i++)
        {
            int minhigh = min(lefthigh[i],righthigh[i]);
            sum += max(0, minhigh - height[i]);
        }
        return sum;
    }
};
/**
 *
 *给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 *
 * 经典题目了：要分析怎样才能把雨水存起来。
 *
 *
 * 这题还能优化很多，空间
 * */