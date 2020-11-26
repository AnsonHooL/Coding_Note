//
// Created by lenovo on 2020/9/13.
//

//双栈模拟队列
class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        if(out.size()!=0)
        {
            int size = out.size();
            for(int i=0; i<size; i++)
            {
                in.push( out.top() );
                out.pop();
            }
        }
        in.push(value);
    }


    int deleteHead() {
        if(in.size()==0 && out.size()==0) return -1;
        if(in.size()!=0)
        {
            int size = in.size();
            for(int i=0;i<size;i++)
            {

                out.push( in.top() );
                in.pop();
            }
        }
        int re = out.top();
        out.pop();
        return  re;

    }
    stack<int> in;
    stack<int> out;
};