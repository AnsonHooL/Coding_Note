//
// Created by lenovo on 2020/9/21.
//


/**** 输出栈此时最小的值 ***/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    void push(int x) {
        if(norS.empty())
        {
            minS.push(x);
            norS.push(x);
        }
        else
        {
            norS.push(x);
            if(x < minS.top()) minS.push(x);
            else minS.push(minS.top());
        }
    }
    void pop() {
        norS.pop();
        minS.pop();
    }
    int top() {
        return norS.top();
    }
    int min() {
        return minS.top();

    }
    stack<int> norS;
    stack<int> minS;
};