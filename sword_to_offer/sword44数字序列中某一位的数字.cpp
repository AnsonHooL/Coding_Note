//
// Created by lenovo on 2020/11/27.
//
class Solution {
public:
    int findNthDigit(int n) {
        // 1: [0, 9]
        // 2: [10, 189] 两位数的10 - 99 对应 10 - 189位 (10 * 2 - 10 至 99 * 2 - 10位)
        // 3: [190, 2889] 三位数的100 - 999 对应 190 - 2889位 (100 * 3 - 110 至 999 * 3 - 110位)
        // 4: [2890, 38889]
        // 5: [38890, 488889]
        // 6: [488890, 5888889]
        // 7: [5888890, 68888889]
        // 8: [68888890, 788888889]
        // 9: [788888890, 8888888889] 88 8888 8889 已经大于21 4748 3648
        if(n<10)
            return n;
        unordered_map<int,pair<long,long>> mymap;
        mymap[1] = pair<long,long>(0,9);
        long dig = 10;
        for(int i=2; i<=9; i++,dig*=10)
        {
            long low = mymap[i-1].second + 1;
            long high = (dig * 9) * i + mymap[i-1].second;
            mymap[i] = pair<long,long>(low,high);
        }
        dig = 1;
        for(int i = 1;i<=9;i++)
        {
            if( n>=mymap[i].first && n<=mymap[i].second)
            {
                if(i == 1) dig = 0;
                else dig = pow(10 , i-1);

                int index = dig;
                dig += (n - mymap[i].first) / i;
                int a = (n - mymap[i].first) % i;
                int c = 0;
                do{
                    c = dig / index;
                    dig = dig % index;
                    index = index / 10;
                    a--;
                }while(a >= 0);
                return c ;
            }
        }
        return 0;

    }
};

/**
 * 先把数据都分好一个个区域，再找在哪个区域的哪个数字
 *
 * */