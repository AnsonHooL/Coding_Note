//
// Created by lenovo on 2021/6/7.
//

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        int mid = -1;
        k = size - k;

        while(mid != k){
            mid = quicksort(nums, low, high);
            if(mid == k) return nums[mid];
            else if(mid < k){
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        // cout<<"x"<<endl;
        return nums[mid];
    }

    int quicksort(vector<int>& arr, int low, int high)  /**这才是标准模板**/
    {
        if(low>=high) return low;

        int i = rand() % (high - low);
        swap(arr[low], arr[low + i]);
        int head = arr[low];

        while(low < high)
        {
            ///这里大于、大于等于都行，绝了
            while(low<high && arr[high] >= head)
//            while(low<high && arr[high] >= head)
            {
                high--;
            }
            arr[low] = arr[high];
            while(low<high && arr[low] <= head)
            {
                low++;
            }
            arr[high] = arr[low];
        }
        arr[low] = head;
        return low;
    }
};

/**
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

我TM


 *
 * */