//
// Created by lenovo on 2020/12/19.
//

class Solution {
public:
    string replaceSpace(string s) {
        string re;
        for(auto ch : s)
        {
            if(ch !=' ')  re += ch;
            else re+= "%20";
        }
        return re;
    }
};