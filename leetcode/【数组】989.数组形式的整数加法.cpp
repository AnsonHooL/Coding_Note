//
// Created by lenovo on 2021/1/22.
//

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size() - 1;
        while(K > 0 && n >= 0)
        {
            int add = K % 10;
            K = K / 10;
            int added = A[n];
            A[n] = (added + add) % 10;
            K += (added + add) / 10;
            n--;
        }
        if(K == 0) return A;

        vector<int> re;
        while(K > 0)
        {
            re.push_back(K % 10);
            K = K / 10;
        }
        reverse(re.begin(), re.end());
        for(auto& a : A) re.push_back(a);

        return re;
    }
};

/**
 * 对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。

给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。

 

示例 1：

输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234
示例 2：

输入：A = [2,7,4], K = 181
输出：[4,5,5]
解释：274 + 181 = 455

思路：就简单的加加加，注意每次进位，进到 K 身上去就行
 * */