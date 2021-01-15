//
// Created by lenovo on 2021/1/14.
//

#include <bits/stdc++.h>
/****/
template <typename ... Tail> class Tuple{};/****一个泛化的接收0~n个模板参数的类***/

//template<> class Tuple<> {}; /****偏特化没有模板参数的类，为下面递归的继承提供尽头***/

template <typename Value, typename ... Tail>
class Tuple<Value, Tail ...> : Tuple<Tail ...> {   /****偏特化至少有一个模板参数的类，继承于0~n-1个模板参数的类(递归在这一行发生), 注意偏特化的语法***/
    Value Val;
public:
    Tuple()
    {
        printf("2333\n");
    };
    Tuple(Value value, Tail ... tail) : Val(value), Tuple<Tail ...>(tail ...) /**Tuple不是成员，是递归的调用继承的父类的构造函数（传了this指针？）**/
    {
        printf("father ctor\n");
    }
    Value value() { return Val; }
    Tuple<Tail ...> next() { return *this; }
};



int main() {
    Tuple<char, double, std::string> tuple('1', 10.1, "Hello World");
    Tuple<> a;
    std::cout << tuple.value() << std::endl;
    std::cout << tuple.next().value() << std::endl;
    std::cout << tuple.next().next().value() << std::endl;
    return 0;
}
