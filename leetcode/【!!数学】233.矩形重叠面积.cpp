//
// Created by lenovo on 2021/3/4.
//

//
// Created by THL on 2021/2/2.
//

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long s1 = (C - A) * (D -B);
        long s3 = (G - E) * (H - F);
        long l1 = 0,l2 = 0;
        if(min(C,G) > max(A,E))
            l1 = min(C,G) - max(A,E);
        if(min(H,D) > max(F,B))
            l2 = min(H,D) - max(F,B);
        if(s1>0 && s3>0 && l1>0 && l2>0) return s1 - l1*l2 + s3 ;
        else return s1 + s3;
    }
};
/**
 * 将二维变成一维进行思考，阿西吧
 *
 * */