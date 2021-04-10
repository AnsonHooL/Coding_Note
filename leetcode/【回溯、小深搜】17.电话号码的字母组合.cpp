//
// Created by lenovo on 2021/4/10.
//

vector<vector<char>>  myvec ={
        {},
        {},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
};

class Solution {
public:

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return vector<string>{};
        vector<string> re = {""};
        for(int i = 0; i < digits.size();i++)
        {
            int size = re.size();
            vector<string> tmp;
            int num = digits[i] - '0';
            for(int j = 0; j < size; j++)
            {
                for(auto c : myvec[num])
                {
                    tmp.push_back(re[j] + c);
                }
            }
            swap(tmp,re);
        }
        return re;
    }
};
/**
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。


 * */