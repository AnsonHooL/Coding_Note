//
// Created by lenovo on 2020/12/19.
//

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i = 0; int j = numbers.size() - 1;
        while(i < j)
        {
            int m = (i+j)/2;
            if(numbers[m] < numbers[j]) j = m;
            else if(numbers[m] > numbers[j]) i = m+1;
            else if(numbers[m] == numbers[j]) j--;
        }
        return numbers[i];
    }
};


/***
 *
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：

输入：[3,4,5,1,2]
输出：1

 **/

///3 4 5 6 7 1 2 3
/// i = 0  j = 7 , m = i+j/2 , m < j 在右排序区间 ， m > j在左排序区间
/// m == j，在哪个排序区间不能确定  1 0 1 1 1, 可以证明 j = j - 1缩小区间 是对的
///                            1 1 1 0 1

