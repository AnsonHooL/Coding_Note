//
// Created by lenovo on 2020/9/20.
//

/**  判断是否为合格的数字 5.0E-2
 *   巧妙的在最后设置一个结束符‘@’
 *   A.BEC  判断A、C为有符号正数，B为无符号整数
 *
 * **/

class Solution {
public:
    bool isNumber(string s) {
        int index = 0;
        bool numeric;
        s = s + string("@");
        while(s[index] == ' ') index++;
        numeric = issignedInter(s,index);
        if(s[index] == '.')
        {
            index++;
            numeric =  isunsignedInter(s,index) || numeric;
        }
        if(s[index] == 'e' || s[index] == 'E')
        {
            index++;
            numeric = numeric && issignedInter(s,index);
        }
        while(s[index] == ' ') index++;

        return numeric && s[index] == '@';

    }

    bool isunsignedInter(const string& s,int& index)
    {
        int before = index;
        while(s[index] >= '0' && s[index] <= '9' )
        {
            index++;
        }
        return index>before;
    }
    bool issignedInter(const string& s,int& index)
    {
        if(s[index] == '+' || s[index] == '-')
            index++;
        return isunsignedInter(s,index);
    }


};