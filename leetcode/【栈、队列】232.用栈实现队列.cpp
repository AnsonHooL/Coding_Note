//
// Created by lenovo on 2021/3/5.
//

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {

        stackin.push(x);

    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!stackout.empty())
        {
            int re = stackout.top();
            stackout.pop();
            return re;
        } else if(!stackin.empty())
        {
            while (!stackin.empty())
            {
                stackout.push(stackin.top());
                stackin.pop();
            }
            int re = stackout.top();
            stackout.pop();
            return re;
        }
        return -1;
    }

    /** Get the front element. */
    int peek() {
        if(!stackout.empty())
        {
            int re = stackout.top();
            return re;
        } else if(!stackin.empty())
        {
            while (!stackin.empty())
            {
                stackout.push(stackin.top());
                stackin.pop();
            }
            int re = stackout.top();
            return re;
        }
        return -1;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stackin.empty() && stackout.empty();

    }
    stack<int> stackin;
    stack<int> stackout;

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */