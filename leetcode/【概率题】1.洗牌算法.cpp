//
// Created by lenovo on 2021/3/25.
//

///一副牌怎么打乱，得到完全随机的一副乱牌

void shuffle(int card[N])
{
    for(int i = N -1; i >= 0; i--)
    {
        swap(card[i], card[rand(0,i)])
    }
}

///从后往前，每个位置随机选取一张牌放置，然后就固定不动，继续往前
///假设N = 5
///最后一张牌的概率是 1/5
///倒数第二张概率是 4/5 * 1/4 = 1/5
///都是1/N