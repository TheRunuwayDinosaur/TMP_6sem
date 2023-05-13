#include <bits/stdc++.h>

using namespace std;

class IEngine{
public:
    virtual void releaseEngine() = 0;
    virtual ~IEngine() = default;
};

class JapaneseEngine : public IEngine{
public:
    void releaseEngine() override{
        std::cout << "японский двигатель\n";
    }
};

class RussianEngine : public IEngine{
public:
    void releaseEngine() override{
        std::cout << "русский двигатель\n";
    }
};

class ICar{
public:
    virtual void releaseCar(IEngine *engine) = 0;
    virtual ~ICar() = default;
};

class JapaneseCar : public ICar{
public:
    void releaseCar(IEngine *engine) override{
        std::cout << "Собрали японский автомобиль: ";
        engine->releaseEngine();
    }
};

class RussianCar : public ICar{
public:
    void releaseCar(IEngine *engine) override{
        std::cout << "Собрали русский автомобиль: ";
        engine->releaseEngine();
    }
};

class IFactory{
public:
    virtual IEngine *createEngine() = 0;
    virtual ICar *createCar() = 0;
    virtual ~IFactory() = default;
};

class JapaneseFactory : public IFactory{
public:
    IEngine *createEngine() override{
        return new JapaneseEngine();
    }
    ICar *createCar() override{
        return new JapaneseCar();
    }
};

class RussianFactory : public IFactory{
public:
    IEngine *createEngine() override{
        return new RussianEngine();
    }
    ICar *createCar() override{
        return new RussianCar();
    }
};

int main(){
    system("chcp 65001");
    IFactory *jFactory = new JapaneseFactory();
    IEngine *jEngine = jFactory->createEngine();
    ICar *jCar = jFactory->createCar();
    jCar->releaseCar(jEngine);

    IFactory *rFactory = new RussianFactory();
    IEngine *rEngine = rFactory->createEngine();
    ICar *rCar = rFactory->createCar();
    rCar->releaseCar(rEngine);
}