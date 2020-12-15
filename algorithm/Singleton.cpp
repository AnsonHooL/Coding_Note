//
// Created by lenovo on 2020/12/2.
//

//TODO：这是安全的饿汉，有没有懒汉模式

class Singleton
{
public:
    Singleton(const Singleton& other) = delete;
    Singleton& operator=(const Singleton& other) = delete;
    Singleton(const Singleton&& other) = delete;
    Singleton& operator=(const Singleton&& other) = delete;
    ~Singleton() = default;
    static Singleton& getSingleton()
    {
        static Singleton instance;
        return instance;
    };

private:
    Singleton() = default;
};

class A
{

};

int main()
{
    Singleton& instance = Singleton::getSingleton();
    A a;
}