//
// Created by lenovo on 2020/9/23.
//
/*****二叉搜索树 给定后序遍历，判断时候是一颗树，重要的是分治****/
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() <= 1) return true;
        return helporder(postorder,0,postorder.size() - 1);
    }
    bool helporder(vector<int>& vec, int low, int high)
    {
        if(low >= high-1)
            return true;
        int root = vec[high];
        int i=9999999;
        for(i = high-1;i>=low;i--)
        {
            if(vec[i] < root) break;
        }
        int lowlimt = i;
        for(;i>=low;i--)
        {
            if(vec[i] > root) return false;
        }
        return helporder(vec,low,lowlimt) && helporder(vec,lowlimt+1,high-1);
    }
};