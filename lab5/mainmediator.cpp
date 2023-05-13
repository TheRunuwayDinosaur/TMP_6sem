#include <bits/stdc++.h>

using namespace std;

class Employee;

class Manager{
public:
    virtual void Modify(Employee *emp,string msg) = 0;
    virtual ~Manager() = default;
};

class Employee{
public:
    explicit Employee(Manager *man = nullptr) : manager(man){

    }
    void setMediator(Manager *man){
        manager = man;
    }
    virtual ~Employee() = default;
protected:
    Manager *manager;
};

class Programmer : public Employee{
public:
    explicit Programmer(Manager *med = nullptr) : Employee(med){

    }
    void executeWork(){
        std::cout << "<-Программист в работе\n";
        manager->Modify(this,"программист кодит...");
    }
    void setWork(bool state){
        isWorking = state;
        if (state) std::cout << "<-Программист освобождён от работы\n";
        else std::cout << "<-Программист занят\n";
    }
private:
    bool isWorking;
};

class Timlid : public Employee{
public:
    explicit Timlid(Manager *med = nullptr) : Employee(med){

    }
    void giveCommand(string txt){
        text = txt;
        if (text.empty()) std::cout << "->Тимлид знает, что программист уже работает\n";
        else std::cout << "->Тимлид дал команду: " << ' ' << text << "\n";
        manager->Modify(this,text);
    }
private:
    string text;
};

class Controller : public Manager{
public:
   Controller(Programmer *des, Timlid *dir){
       designer = des;
       director = dir;
       designer->setMediator(this);
       director->setMediator(this);
   }
   void Modify(Employee *emp,string msg) override{
       if (auto dir = dynamic_cast<Timlid*>(emp)){
           if (msg.empty()) designer->setWork(false);
           else designer->setWork(true);
       }
       if (auto des = dynamic_cast<Programmer*>(emp)){
           if (msg == "программист кодит...") director->giveCommand("");
       }
   }
private:
    Programmer *designer;
    Timlid *director;
};

int main(){
    system("chcp 65001");
    auto *programmer = new Programmer();
    auto *director = new Timlid();
    auto *manager = new Controller(programmer, director);
    director->giveCommand("Разработать ПО");
    std::cout << "\n";
    programmer->executeWork();
    delete programmer;
    delete director;
    delete manager;
}