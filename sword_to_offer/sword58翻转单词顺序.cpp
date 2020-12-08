//
// Created by lenovo on 2020/12/7.
//

class Solution {
public:
    string reverseWords(string s) {
        int high = s.size() - 1;
        string re;
        while(high>=0)
        {
            while(high>=0 &&  s[high] == ' ')
            {
                high--;
            }

            int low = high;
            while(low >=0 && s[low] != ' ')
            {
                low--;
            }
            if(low == high) break;
            string tmp(s.begin() + low + 1,s.begin() + high + 1);
//            cout<< "###"<< tmp<<"###"<<endl;
            high = low;
            if(re.empty()) re = std::move(tmp);
            else
            {
                re.append(" ");
                re.append(tmp);
            }

        }
        return re;
    }
};


class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string res,str;
        istringstream ss(s);
        while (ss >> str) stk.push(str), stk.push(" ");
        if (!stk.empty()) stk.pop();
        while (!stk.empty()) res += stk.top(), stk.pop();
        return res;
    }
};




/***
 *
 *输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

思路一：从后往前算就行
 思路二：利用stl库istringstream和栈，简单代码
 *
 *
 * /