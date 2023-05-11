#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class MIREA;
class Cinema;

class MyVisitor{
public:
    virtual void visit(MIREA &ref) = 0;
    virtual void visit(Cinema &ref) = 0;
    virtual ~MyVisitor() = default;
};

class Place{
public:
    virtual void accept(MyVisitor &visitor) = 0;
    virtual ~Place() = default;
};

class MIREA : public Place{
public:
    void accept(MyVisitor &visitor) override{
        visitor.visit(*this);
    }
};

class Cinema : public Place{
public:
    void accept(MyVisitor &visitor) override{
        visitor.visit(*this);
    }
};

class WasVisited : public MyVisitor{
public:
    string value;
    void visit(MIREA &mirea) override{
        value = "Пришёл на 4 пару Сергея Викторовича";
    }
    void visit(Cinema &cinema) override{
        value = "Увидел в кино Форсаж 10";
    }
};
int main(){
    system("chcp 65001");
    MIREA mirea;
    Cinema cinema;
    Place *places[] = {&mirea,&cinema};
    for (auto& place : places){
        WasVisited visitor;
        place->accept(visitor);
        std::cout << visitor.value << "\n";
    }
}