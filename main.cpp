#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cstring>
#include <queue>
#include <cmath>
#include <bitset>
#include <deque>
#include <memory>
#include <thread>
#include "zconf.h"

using namespace std;
// n*m


#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

void f1()
{
    int n = 0;
    for (int i = 0; i < 50; ++i) {
        printf("Thread %d excuting\n",i);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    char * a = new char[1024*1024*50];
    memset(a,0,50*1024*1024);
}

void f2(int& n)
{
    for (int i = 0; i < 50; ++i) {
        printf("Thread 2 executing\n");
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main()
{
    int n = 0;
//    std::thread t1; // t1 is not a thread
//    std::thread t2(f1); // pass by value
    std::thread* t3 = new std::thread(f1);
//    t3->join();
    printf("wait for child thread\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));
//    std::thread t3(f2, std::ref(n)); // pass by reference
//    std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
//    t2.join();
//    t4.join();

    std::cout << "Final value of n is " << n << '\n';
}