//
// Created by lenovo on 2021/5/11.
//

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int ABCDE = 0;
        int n = encoded.size();
        vector<int> perm(n+1);
        int BCDE = 0;
        for(int i = 1; i <= n+1; i++){
            ABCDE = ABCDE ^ i;
        }
        for(int i = 1; i < n; i+=2){
            BCDE = BCDE ^ encoded[i];
        }
        int A = BCDE ^ ABCDE;
        perm[0] = A;
        for(int i = 0;i < n; i++){
            perm[i+1] = perm[i] ^ encoded[i];
        }
        return perm;
    }
};

/**
 * 给你一个整数数组 perm ，它是前 n 个正整数的排列，且 n 是个 奇数 。

它被加密成另一个长度为 n - 1 的整数数组 encoded ，满足 encoded[i] = perm[i] XOR perm[i + 1] 。比方说，如果 perm = [1,3,2] ，那么 encoded = [2,1] 。

给你 encoded 数组，请你返回原始数组 perm 。题目保证答案存在且唯一。

 

示例 1：

输入：encoded = [3,1]
输出：[1,2,3]
解释：如果 perm = [1,2,3] ，那么 encoded = [1 XOR 2,2 XOR 3] = [3,1]
示例 2：

输入：encoded = [6,5,4,6]
输出：[2,4,1,5,3]

思路：ABCDE，以后BC DE 得到A，就能解决了
 * */