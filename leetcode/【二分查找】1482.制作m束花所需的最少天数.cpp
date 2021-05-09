//
// Created by lenovo on 2021/5/9.
//

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size())
            return -1;
        int maxday = INT32_MIN;

        for(auto day : bloomDay) maxday = max(maxday, day);

        int minday = 1;

        while(minday < maxday){

            int midday = (minday + maxday) / 2;

            if(check(bloomDay,midday,m,k)){

                maxday = midday;

            } else{
                minday = midday + 1;
            }
        }
        return minday;
    }


    bool check(vector<int>& bloomDay, int day, int m , int k){
        int count = 0;
        int n = 0;
        for(int i = 0; i < bloomDay.size();i++){
            if(bloomDay[i] <= day)
            {
                n++;
                if(n == k){
                    count++;
                    n = 0;
                    if(count == m) return true;
                }

            } else{
                n = 0;
            }
        }
        return false;
    }

};

/**
 * 给你一个整数数组 bloomDay，以及两个整数 m 和 k 。

现需要制作 m 束花。制作花束时，需要使用花园中 相邻的 k 朵花 。

花园中有 n 朵花，第 i 朵花会在 bloomDay[i] 时盛开，恰好 可以用于 一束 花中。

请你返回从花园中摘 m 束花需要等待的最少的天数。如果不能摘到 m 束花则返回 -1 。

 

示例 1：

输入：bloomDay = [1,10,3,10,2], m = 3, k = 1
输出：3
解释：让我们一起观察这三天的花开过程，x 表示花开，而 _ 表示花还未开。
现在需要制作 3 束花，每束只需要 1 朵。
1 天后：[x, _, _, _, _]   // 只能制作 1 束花
2 天后：[x, _, _, _, x]   // 只能制作 2 束花
3 天后：[x, _, x, _, x]   // 可以制作 3 束花，答案为 3
示例 2：

输入：bloomDay = [1,10,3,10,2], m = 3, k = 2
输出：-1
解释：要制作 3 束花，每束需要 2 朵花，也就是一共需要 6 朵花。而花园中只有 5 朵花，无法满足制作要求，返回 -1 。


 思路：这个就是二分咯，暴力二分
 *
 * */