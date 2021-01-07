//
// Created by lenovo on 2020/12/2.
//

#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>

//TODO:1.内存模型，指令序列
//TODO:2，性能优化，空转
class RWlock
{
private:
    std::atomic<uint32_t> Flag;
public:
    RWlock(const RWlock&) = delete;
    RWlock& operator=(const RWlock&) = delete;
    RWlock() noexcept : Flag(0) {}

    ///第一个bit分配给写锁，其他bit分配给读锁
    ///写锁优先级高于读锁
    void Lockread() noexcept
    {
        uint32_t expected = Flag.load() & 0x7fffffff;
        while(!Flag.compare_exchange_weak(expected,expected+1))
        {
            expected &= 0x7fffffff;
        }
    }
    void Unlockread() noexcept
    {
        Flag--;
    }

    void Lockwrite() noexcept
    {
        uint32_t expected = Flag.load() & 0x7fffffff;
        while(!Flag.compare_exchange_weak(expected,expected + 0x80000000))
        {
            expected &= 0x7fffffff; ///先把锁占住，这时候不能加新的读锁和写锁
        }
        while(Flag.load() & 0x7fffffff != 0)
        {
            ///等待读完毕
        }
    }
    void  Unlockwrite() noexcept
    {
        Flag -= 0x80000000;
    }
};


int num = 0;
RWlock glock;
std::mutex lock;

void read(int x)
{
    int count = 10;
    while (count--)
    {
        glock.Lockread();
//        lock.lock();
        printf("%d read  : %d\n",x,num);
//        lock.unlock();
        glock.Unlockread();
    }

}

void write(int x)
{
    int count = 10;
    while (count--)
    {
        glock.Lockwrite();
//        lock.lock();
        printf("%d write : %d\n",x,++num);
//        lock.unlock();
        glock.Unlockwrite();
    }

}

int main()
{
    std::thread t1(read,1);
    std::thread t2(write,2);
    std::thread t3(read,3);
    std::thread t4(write,4);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}





























///https://zhuanlan.zhihu.com/p/86508499