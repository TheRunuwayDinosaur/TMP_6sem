#include <bits/stdc++.h>

using namespace std;

class Phone{
public:
    Phone(){
        data = "";
    }
    string aboutPhone() {
        return data;
    }
    void appendData(string num){
        data += num;
    }
private:
    string data;
};

class IDeveloper{
public:
    virtual void createDisplay() = 0;
    virtual void createBox() = 0;
    virtual void systemInstall() = 0;
    virtual Phone *get_phone() = 0;
};

class AndroidDeveloper : public IDeveloper{
public:
    AndroidDeveloper(){
        phone = new Phone();
    }
    ~AndroidDeveloper() {
        delete phone;
    }
    void createDisplay() override{
        phone->appendData("Произведён дисплей Samsung Galaxy; ");
    }
    void createBox() override{
        phone->appendData("Произведён корпус Samsung; ");
    }
    void systemInstall() override{
        phone->appendData("Установлена система Android; ");
    }
    Phone *get_phone() override{
        return phone;
    }
private:
    Phone *phone;
};

class Director{
public:
    explicit Director (IDeveloper *dev) : developer(dev){

    }
    void setDeveloper(IDeveloper *new_dev){
        developer = new_dev;
    }
    Phone *MountOnlyPhone(){
        developer->createBox();
        developer->createDisplay();
        return developer->get_phone();
    };
    Phone *MountFullPhone(){
        developer->createBox();
        developer->createDisplay();
        developer->systemInstall();
        return developer->get_phone();
    }
private:
    IDeveloper *developer;
};
int main(){
    system("chcp 65001");
    IDeveloper *developer = new AndroidDeveloper();
    Director director(developer);
    Phone *samsungS9plus = director.MountFullPhone();
    std::cout << samsungS9plus->aboutPhone();
}