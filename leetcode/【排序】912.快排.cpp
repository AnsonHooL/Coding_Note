//
// Created by lenovo on 2020/12/11.
//

//
// Created by lenovo on 2020/10/10.
//

class Solution{
public:
    vector<int> sortArray(vector<int>& nums) {

        dosort(nums,0,nums.size()-1);
        return nums;

    }

    void dosort(vector<int>& nums, int low, int high)
    {
        if(low>=high)
            return;
        int m = quicksort(nums,low,high);
        dosort(nums,low,m-1);
        dosort(nums,m+1,high); /**这里要+1**/
    }
    int quicksort(vector<int>& arr, int low, int high)  /**这才是标准模板**/
    {
        int i = rand() % (high - low);
        swap(arr[low], arr[low + i]);
        int head = arr[low];


        if(low>=high) return low;
        while(low < high)
        {
            ///这里大于、大于等于都行，绝了
            while(low<high && arr[high] > head)
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


///快排模板，0，0确定边界或者背,记住用高位+1
class Solution {
public:
    void quick_sort(vector<int>& q, int l, int r)
    {
        if (l >= r) return;

        int i = l - 1, j = r + 1, x = q[l + r >> 1];
        while (i < j)
        {
            do i ++ ; while (q[i] < x);
            do j -- ; while (q[j] > x);
            if (i < j) swap(q[i], q[j]);
        }
        quick_sort(q, l, j), quick_sort(q, j + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums,0,nums.size()-1);
        return nums;
    }
};