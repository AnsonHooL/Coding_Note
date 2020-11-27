//
// Created by lenovo on 2020/11/27.
//

bool cmp(int a, int b){   //升序排列，小的数字放在前面 10,100  10100 10010 判断的是从高位到低位

//    string atmp = to_string(a) + to_string(b);
//    string btmp = to_string(b) + to_string(a);
    return to_string(a) + to_string(b) < to_string(b) + to_string(a);//按降序排序
}

class Solution {
public:
    string minNumber(vector<int>& nums) {

        auto cmp1 = [](int a, int b) ->bool {return to_string(a) + to_string(b) < to_string(b) + to_string(a);};
        //lambada
        //按降序排序
        sort(nums.begin(),nums.end(),cmp1);

        string rec;
        char t[40];
        for(auto x : nums)
        {
            sprintf(t,"%d",x);
            rec += string(t);
            cout << t << endl;
        }
        return rec;
    }
};


/**
 *
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

示例 1:

输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"

 解题思路：重要的是排序，排序最简洁的方法就是用字符串拼接 a+b < b+a进行比较，
 sort 的 cmp 是确定a是否放在前面
 *
 *
 * */