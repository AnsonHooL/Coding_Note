//
// Created by lenovo on 2020/12/8.
//

class MaxQueue {
public:
    deque<int> que;
    deque<int> help;
    MaxQueue() {

    }

    int max_value() {
        if(que.empty()) return -1;
        else return help.front();

    }

    void push_back(int value) {
        while(!help.empty() && help.back()<value) help.pop_back();
        help.push_back(value);
        que.push_back(value);

    }

    int pop_front() {
        if(que.empty()) return -1;
        int re = que.front();
        que.pop_front();
        if(!help.empty() && re == help.front()) help.pop_front();
        return re;

    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 *
 * 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

思路:维护一个单调队列即可，每个新来的值从后往前，将所有小于它的pop
 popqueue时候，判断退出的是否队列的最大值。
 */