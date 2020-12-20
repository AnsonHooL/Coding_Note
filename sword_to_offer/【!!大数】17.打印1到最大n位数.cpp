//
// Created by lenovo on 2020/9/18.
//
/***  难点是大数乘法  ***/
class Solution {
public:
    vector<int> printNumbers(int n) {
        int max = 0;
        vector<int> tmp;
        max = pow(10,n)-1;
        for(int i=1;i<=max;i++)
        {
            tmp.push_back(i);
        }
        return tmp;
    }
};

///打印 1 ~ 99999999999999
///方法是从高位开始固定 0~9，不断的递归，若前面全是0，则不添加字符
void dfs(int pos, string s, int n)
{
    if (pos == n)
    {
        if(s != "") cout << s << endl;
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if(s != "" || (s == "" && i != 0)) s += to_string(i);
        dfs(pos + 1,s,n);
        s = s.substr(0, s.size()-1);
    }
}

dfs(0,"",2);
