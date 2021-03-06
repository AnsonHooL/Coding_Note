//
// Created by lenovo on 2020/12/16.
//

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        count = 0;
    }

    void addNum(int num) {
        if(count%2 == 0) //存到大根堆
        {
            smallheap.push(num);
            bigheap.push(smallheap.top());
            smallheap.pop();
        }else if(count%2 == 1)
        {
            bigheap.push(num);
            smallheap.push(bigheap.top());
            bigheap.pop();
        }
        count++;
    }

    double findMedian() {
        if(count == 0) return 0;
        if(count % 2 == 1) return bigheap.top();
        else return (bigheap.top() + smallheap.top())/2.0;
        return 0;
    }

    ///大根堆保存小的一半数字，小根堆保存大的一半数字
    ///大根堆个数大于1或者等于小根堆
    int count;
    priority_queue<int,vector<int>,less<int>> smallheap;
    priority_queue<int,vector<int>,greater<int>> bigheap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/****
 *如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]

思路：维护两个堆，一个大根堆，保存数组小一半的数字，一个小根堆，保存数组大一半的数字
并且大根堆个数大于1或者等于小根堆,
 那么每次取中位数则，取堆顶即可，插入的时候就按奇数插入大根堆，偶数插入小根堆即可
 *
 *
 *
 *
 */
/