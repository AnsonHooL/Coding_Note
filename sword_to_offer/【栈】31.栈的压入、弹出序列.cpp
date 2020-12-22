//
// Created by lenovo on 2020/9/21.
//



/****给定一个入栈序列，出栈序列 ，判断能不能这样出入*****/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pushnum = 0;
        int popnum  = 0;
        while(popnum < popped.size())
        {
            if(!A.empty() && A.top() == popped[popnum])
            {
                popnum++;
                A.pop();
                continue;
            }
            if(pushnum >= pushed.size()) break;
            A.push(pushed[pushnum]);
            pushnum++;
        }
        return pushnum == pushed.size() && popnum == popped.size();
    }
    stack<int> A;
};