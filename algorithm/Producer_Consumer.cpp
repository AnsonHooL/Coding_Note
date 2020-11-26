//
// Created by lenovo on 2020/11/26.
//

#include <iostream>
#include <cstring>
#include <thread>
#include <condition_variable>
#include "zconf.h"
#include <memory>
using namespace std;
// n*m

int num = 0;
std::mutex global_mutex;
std::condition_variable global_cv;
bool conflag = false;
bool proflag = false;

void consumer(int tid)
{
    conflag = true;
    int con = 0;
    printf("thread :%d start...\n",tid);
    while(conflag)
    {
        {
            std::unique_lock<std::mutex> lockgard(global_mutex);
            while(num)
            {
//                printf("thread id_%d : consume num form %d => %d \n",tid,num,num-1);
                num--;
                con++;
            }
            if(!proflag)
            {
                conflag = false;
            } else
            {
                global_cv.wait(lockgard);
            }
        }
    }
    printf("thread :%d end... consume:%d...\n",tid,con);
}

void producer(int tid)
{
    printf("thread :%d start...\n",tid);
    proflag = true;
    int n = 10000000;
    int p = n;
    while(proflag)
    {
//        std::this_thread::sleep_for(std::chrono::milliseconds(1)); //生产者消费
        std::unique_lock<std::mutex> lockgard(global_mutex);
        if(n)
        {
            n--;
//            printf("thread id_%d : producer(c=%d) num form %d => %d \n",tid,c,num,num+1);
            num++;
        }
        global_cv.notify_one();
        if(n == 0) proflag = false;
    }
    global_cv.notify_all();
    printf("thread :%d end...produce:%d\n",tid,p);
}

int main()
{
    std::thread t1(producer,1);
    std::thread t2(consumer,2);
    std::thread t3(consumer,3);
    std::thread t4(consumer,4);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}