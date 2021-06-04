//
// Created by lenovo on 2021/3/9.
//

class Solution {
public:
//    double findkthele(vector<int>& nums1, vector<int>& nums2, int k)
//    {
//        int len1 = nums1.size();
//        int len2 = nums2.size();
//        int lo = max(0,k-len2);
//        int hi = min(len1,k);
//        while(lo < hi)
//        {
//            int median = lo + (hi-lo)/2;
//
//            if(nums1[median] < nums2[k-median-1]) lo = median+1;
//            else hi = median;
//
//        }
//        int max1,max2;
//        max1 = (lo==0 ? INT16_MIN:nums1[lo-1]);
//        max2 = (lo==k ? INT16_MIN:nums2[k-lo-1]);
//        return max(max1,max2);
//    }

    double findkthele(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 == 0) return nums2[k - 1];
        if(len2 == 0) return nums1[k - 1];

        int low1 = 0, low2 = 0;

        while(k > 1){
            int mid = k / 2;

            int cmpos1 = min(low1 + mid - 1, len1 - 1);
            int cmpos2 = min(low2 + mid - 1, len2 - 1);

            if(nums1[cmpos1] < nums2[cmpos2]){
                k -= (cmpos1 - low1 + 1);
                low1 = cmpos1 + 1;


                if(low1 > len1 - 1) return nums2[low2 + k - 1];
            } else{
                k -= (cmpos2 - low2 + 1);
                low2 = cmpos2 + 1;

                if(low2 > len2 - 1) return nums1[low1 + k - 1];
            }
        }

        return min(nums1[low1], nums2[low2]);
    }

    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if((m+n)%2 == 1) return findkthele(nums1,nums2,(m+n+1)/2.0);
        else return (findkthele(nums1,nums2,(m+n)/2)+findkthele(nums1,nums2,(m+n)/2+1))/2.0;

    }
};

/**
 * 思路：中位数不就是求第 K 个数 或者（k + k+1）/2
 * 然后求变成求第k个数的题目，然后有个超棒的思路：
 * 每次比较前 k/2 的数，然后把小的一部分去掉，然后可以保证最后筛选出的就是第K个数！！！！！！！！！太绝了超简单
 * 其他方法都是什么歪瓜裂枣
 *
 *
 *
 *
 *
 *
 *
 *
 * */