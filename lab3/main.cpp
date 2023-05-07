#include <bits/stdc++.h>
 
using namespace std;
 
class Behaviour{
public:
    virtual long long get_result(int n);
};
 
class Fact : public Behaviour{
public:
    long long get_result(int n){
        long long res = 1;
        for (int i = 1;i <= n;i++) res *= i;
        return res;
    }
};
 
class Sum : public Behaviour{
public:
    long long get_result(int n){
        long long res = 0;
        for (int i = 1;i <= n;i++) res += i;
        return res;
    }
};
 
class Matesha{
public:
    long long get_result(Behaviour *b,int n){
        behaviour = b;
        return b->get_result(n);
    }
    double get_sin(){
        return calc_sin();
    }
    double get_cos(){
        return calc_cos();
    }
private:
    Behaviour *behaviour;
    virtual double calc_sin(){ return sin(136); }
    virtual double calc_cos(){ return cos(150); }
};
 
class Matesha_2 : public Matesha{
public:
    double get_sin(){
        return calc_sin();
    }
    double get_cos(){
        return calc_cos();
    }
protected:
    double calc_sin() override{
        return sin(150);
    }
    double calc_cos() override{
        return sin(136);
    }
};
 
int main(){
    Behaviour *behaviour;
    auto *matesha = new Matesha();
    Sum sumBehave;
    Fact factBehave;
    behaviour = &factBehave;
    std::cout << matesha->get_result(behaviour,10) << "\n";
    Matesha_2 *matesha2 = new Matesha_2();
    std::cout << matesha->get_sin() << ' ' << matesha2->get_sin();
}