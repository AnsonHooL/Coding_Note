//
// Created by lenovo on 2020/10/10.
//

/***** 数组中最小的K个数  ****/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> re;
        if(k<=0) return re;
        sort(arr.begin(),arr.end());
        re.assign(arr.begin(),arr.begin()+k);
        return  re;
    }
};

/****快排****/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> re;
        if(k<=0) return re;
        //sort(arr.begin(),arr.end());
        int low  = 0;
        int high = arr.size()-1;
        int m = quicksort(arr,low,high);
        while(m != k-1)
        {
            if(m < k-1)
            {
                low = m+1;
                m = quicksort(arr,low,high);
            }
            else
            {
                high = m-1;
                m = quicksort(arr,low,high);
            }
        }
        re.assign(arr.begin(),arr.begin()+k);
        return  re;
    }
    int quicksort(vector<int>& arr, int low, int high)
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