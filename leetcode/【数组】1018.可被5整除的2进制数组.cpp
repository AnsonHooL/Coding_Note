//
// Created by lenovo on 2021/1/14.
//

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        vector<bool> res(n);
        for(int i = 0; i < n; i++)
        {
            sum = sum * 2 + A[i];
            res[i] = (sum % 5 == 0);
            sum = sum % 5;
        }
        return res;
    }
};