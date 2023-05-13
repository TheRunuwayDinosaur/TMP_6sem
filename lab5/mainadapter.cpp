#include <bits/stdc++.h>

using namespace std;

class Scales{
public:
    virtual double *getWeight() = 0;
};

class RussianScales : public Scales{
public:
    explicit RussianScales(double *cw) : currentWeight(cw){

    }
    double *getWeight() override{
        return currentWeight;
    }
    ~RussianScales(){
        delete currentWeight;
    }
private:
    double *currentWeight;
};

class BritishScales{
public:
    explicit BritishScales(double *cw) : currentWeight(cw){

    }
    ~BritishScales(){
        delete currentWeight;
    }
    double *getWeight(){
        return currentWeight;
    }
private:
    double *currentWeight;
};

class AdapterForBritishScales : public Scales{
public:
    explicit AdapterForBritishScales(BritishScales *cw) : britishScales(cw),cw(nullptr){

    }
    ~AdapterForBritishScales(){
        delete britishScales;
        delete cw;
    }
    double *getWeight() override{
        cw = britishScales->getWeight();
        *cw *= 0.453;
        return cw;
    }
private:
    BritishScales *britishScales;
    double *cw;
};

int main(){
    system("chcp 65001");
    double kg = 55.0;
    double lb = 55.0;
    Scales *rScales = new RussianScales(&kg);
    Scales *bScales = new AdapterForBritishScales(new BritishScales(&lb));
    std::cout << *rScales->getWeight() << ' ' << *bScales->getWeight();
}