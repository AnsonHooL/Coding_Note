//
// Created by lenovo on 2021/4/23.
//

struct entry{
    int preidnex = 0;
    int dpsize = 0;
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<entry> dp(nums.size());
        sort(nums.begin(),nums.end());
        int maxindex = 0;
        int maxlen = 1;
        for(int i = 0; i < nums.size(); i++){
            dp[i] = {i,1};
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0  && dp[j].dpsize + 1 > dp[i].dpsize){
                    dp[i].preidnex = j;
                    dp[i].dpsize = dp[j].dpsize + 1;
                    if(dp[i].dpsize > maxlen){
                        maxlen = dp[i].dpsize;
                        maxindex = i;
                    }
                }
            }
        }
        vector<int> re;

        while (maxindex != dp[maxindex].preidnex){

            re.push_back(nums[maxindex]);
            maxindex = dp[maxindex].preidnex;

        }
        re.push_back(nums[maxindex]);
        return re;
    }
};

/**
 * 给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
answer[i] % answer[j] == 0 ，或
answer[j] % answer[i] == 0
如果存在多个有效解子集，返回其中任何一个均可。

 

示例 1：

输入：nums = [1,2,3]
输出：[1,2]
解释：[1,3] 也会被视为正确答案

思路：
 这题就是最长上升子序列的完全变种题目，一模一样
 只是条件由，变大能放到后面，变成了如果后面的能整除前面的就能放到前面
 dp[i] = 以第i个数结尾的最大子集，后面的数只要判断是第i个数的倍数就行，因为从小到大，肯定和前面的都是倍数关系
 动规啊居然没想到这个递增的关系！

 *
 * */