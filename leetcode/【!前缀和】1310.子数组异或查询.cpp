//
// Created by lenovo on 2021/5/12.
//

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> preXOR(n + 1, 0); // “前缀和”初始化
        for(int i = 0; i < n; i ++) preXOR[i + 1] = arr[i] ^ preXOR[i]; // 得到“前缀和”
        vector<int> xorRange; // 区间异或结果
        for (auto & query : queries) { // 得到区间左右边界
            int left = query[0], right = query[1];
            xorRange.push_back(preXOR[right + 1] ^ preXOR[left]); // 得到区间异或结果
        }
        return xorRange;
    }
};

/**
 * 有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。

对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。

并返回一个包含给定查询 queries 所有结果的数组。

 

示例 1：

输入：arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
输出：[2,7,14,8]
解释：
数组中元素的二进制表示形式是：
1 = 0001
3 = 0011
4 = 0100
8 = 1000
查询的 XOR 值为：
[0,1] = 1 xor 3 = 2
[1,2] = 3 xor 4 = 7
[0,3] = 1 xor 3 xor 4 xor 8 = 14
[3,3] = 8

思路：
 还是前缀和的思路，一次性求出前面一堆的Xor之汇总结果
 *
 * */