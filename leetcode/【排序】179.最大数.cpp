//
// Created by lenovo on 2021/4/12.
//

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [](int l, int r) {
            string lstr = to_string(l);
            string rstr = to_string(r);
            return (lstr + rstr) > (rstr + lstr);
        };
        sort(nums.begin(), nums.end(), cmp);
        string re;
        for (auto num : nums) {

            re += to_string(num);
        }

        if(re[0] == '0')
        {
            int i;
            for(i = 0; i < re.size() && re[i] == '0'; i++)
            {
            }
            i--;
            return re.substr(i);
        }
        return re;
    }
};
/**
 * 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。

注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

 

示例 1：

输入：nums = [10,2]
输出："210"
示例 2：

输入：nums = [3,30,34,5,9]
输出："9534330"

转成字符串排序就行
 *
 * */