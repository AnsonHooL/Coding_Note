//
// Created by lenovo on 2020/12/30.
//

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 0)
            return 0;

        priority_queue<int , vector<int>, less<int>> myheap; ///大根堆，也是默认模式

        for(auto x:stones)
        {
            myheap.push(x);
        }

        while (myheap.size() > 1)
        {
            int x = myheap.top(); myheap.pop();
            int y = myheap.top(); myheap.pop();
            x -= y;
            if(x > 0) myheap.push(x);
        }

        if(myheap.size() == 0) return 0;

        return myheap.top();
    }
};

/**
 * 有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

 

思路：搞一个堆，每次取最大的两个石头出来玩

 * */