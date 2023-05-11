#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

class MyStack{
public:
    friend class MyStackIterator;
    explicit MyStack(int len){
        sz = -1;
        a.resize(len);
    }
    void push(int val){
        a[++sz] = val;
    }
    int pop(){
        return a[sz--];
    }
private:
    int sz;
    vector <int> a;
};

class MyStackIterator{
public:
    explicit MyStackIterator(const MyStack &st) : stack(st){
        i = 0;
    }
    void operator++(){
        i++;
    }
    int operator*(){
        return stack.a[i];
    }
    bool operator()(){
        return i != stack.sz + 1;
    }
private:
    const MyStack &stack;
    int i;
};

bool operator==(const MyStack &stack1,const MyStack &stack2){
    MyStackIterator iter1(stack1),iter2(stack2);
    for (;iter1();++iter1,++iter2){
        if (*iter1 != *iter2) break;
    }
    return !iter1() && !iter2();
}

int main(){
	system("chcp 65001");
    MyStack stack1(100);
    std::uniform_int_distribution<int> dist((int)1, (int)1e9);
    static std::mt19937 gen(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int i = 0;i < 100;i++){
        stack1.push(dist(gen));
    }
    MyStack stack2(stack1);
    if (stack1 == stack2) std::cout << "Равны!\n";
    else std::cout << "Не равны :(\n";
    stack2.push(dist(gen));
    if (stack1 == stack2) std::cout << "Равны!\n";
    else std::cout << "Не равны :(\n";
}