//
// Created by lenovo on 2020/12/2.
//

#include <atomic>
#include <iostream>
#include <thread>
using namespace std;
class mutex{
    std::atomic_int flag;
public:
    mutex() {flag.store(0);}
    mutex(const mutex& other) = delete;
    mutex& operator=(const mutex& other) = delete;
    mutex(mutex && other) = delete;
    mutex&operator=(mutex&& other) = delete;
    void lock()
    {
        int expected = 0;
        while (!flag.compare_exchange_strong(expected,1)) { expected = 0; }
    }
    void unlock()
    {
        flag.store(0);
    }
};

class mutex1{
    std::atomic_flag flag;

public:

    mutex1(const mutex1& other) = delete;
    mutex1& operator=(const mutex1& other) = delete;
    mutex1(mutex1 && other) = delete;
    mutex1&operator=(mutex1&& other) = delete;
    mutex1(): flag(ATOMIC_FLAG_INIT) {}
    void lock()
    {
        while (flag.test_and_set()) {  }
    }
    void unlock()
    {
        flag.clear();
    }
};


//mutex mtx;
mutex mtx1;

void print_block(char c)
{
    mtx1.lock();
    for(int i =0;i<8;i++) {std::cout << c;}
    std::cout<<endl;
    mtx1.unlock();
}

int main()
{
    std::thread t1(print_block,'*');
    std::thread t2(print_block,'$');
    std::thread t3(print_block,'=');
    std::thread t4(print_block,'+');
    std::thread t5(print_block,'0');
    std::thread t6(print_block,'5');
    std::thread t7(print_block,'3');
    std::thread t8(print_block,'1');
    std::thread t9(print_block,';');

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();

}























