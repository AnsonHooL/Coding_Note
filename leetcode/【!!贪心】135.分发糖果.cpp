//
// Created by lenovo on 2020/12/24.
//
/***
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2:

输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

*/

///第一种思路，会超时
///所有人先分配一个糖果，从左到右，若右边比左边的大，则左边的同学加一个糖果（不断的往左看去加一个糖果）
///只有若是  5 4 3 2 1 递减，则时间复杂度O（n*n）
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> greedy(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i] > ratings[i-1]) greedy[i] = greedy[i-1] + 1;
            else if(ratings[i] == ratings[i-1]) continue;
            else if(ratings[i] < ratings[i-1] && greedy[i] >= greedy[i-1])
            {
                int pos = i-1;
                while(pos >= 0)
                {
                    greedy[pos] = greedy[pos + 1] + 1;
                    pos--;
                    if(pos < 0 || (ratings[pos] <= ratings[pos+1]) ||(ratings[pos] > ratings[pos+1] && greedy[pos] > greedy[pos + 1]) ) break;
                }
            }
        }
        int sum = 0;
        for(auto x : greedy)
        {
            sum += x;
        }
        return sum;
    }
};

///题目等于满足（A，B），若A>B  ,  A糖果更多，   若B>A，  B糖果更多，同时满足这两个条件即可
///从左到右算一遍，从右到左算一遍，取最大
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> greedyleft(ratings.size(), 1);
        vector<int> greedyright(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i] > ratings[i-1]) greedyleft[i] = greedyleft[i-1] + 1;
        }
        for(int i = ratings.size() - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i+1]) greedyright[i] = greedyright[i+1] + 1;
        }
        int sum = 0;
        for(int i = 0; i < ratings.size(); i++)
        {
            sum += max(greedyleft[i], greedyright[i]);
        }
    }
};
