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
        int head = arr[low];
        if(low>=high) return low;
        while(low < high)
        {
            while(low<high && arr[high] >= head)
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