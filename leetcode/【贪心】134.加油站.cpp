//
// Created by lenovo on 2021/3/4.
//

///解法一：
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> delta(n,0);
        for(int i = 0; i < n; i++)
        {
            delta[i] = gas[i] - cost[i];
        }

        for(int i  = 0; i < n; )
        {
            int value = 0;
            int j = 0;
            for(j = 0; j < n; j++)
            {
                value += delta[(i + j) % n];
                if(value < 0) break;
            }
            if(j == n) return i;
            i += j;
        }
        return -1;
    }
};

///优化方法，就是加油站可以跳过去的，不是每次加一，而是将若干个加油站合并成一个，直接跳过加油站
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> delta(n,0);
        for(int i = 0; i < n; i++)
        {
            delta[i] = gas[i] - cost[i];
        }

        for(int i  = 0; i < n; )
        {
            int value = 0;
            int j = 0;
            for(j = 0; j < n; j++)
            {
                value += delta[(i + j) % n];
                if(value < 0) break;
            }
            if(j == n) return i;
            i += (j + 1);    ///这里优化了
        }
        return -1;
    }
};


/**
 * 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

说明: 

如果题目有解，该答案即为唯一答案。
输入数组均为非空数组，且长度相同。
输入数组中的元素均为非负数。


 思路：贪心算法即可，暴力O（n2）
 * */