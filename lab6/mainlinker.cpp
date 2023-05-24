#include <bits/stdc++.h>
#include <windows.h>
#include <Windows.h>

using namespace std;

class Item{
public:
    Item(string name) : itemName(name){

    }
    void setOwner(string own){
        ownerName = own;
    }
    virtual void add(Item *subItem) = 0;
    virtual void remove(Item *subItem) = 0;
    virtual void display() = 0;
protected:
    string itemName;
    string ownerName;
};

class ClickableItem : public Item{
public:
    ClickableItem(string name) : Item(name){

    }
    void add(Item* subItem) override{
        throw exception();
    }
    void remove(Item *subItem) override{
        throw exception();
    }
    void display() override{
        std::cout << itemName << "\n";
    }
};

class DropDownItem : public Item{
public:
    DropDownItem(string name) : Item(name){

    }
    void add(Item* subItem) override{
        subItem->setOwner(this->itemName);
        children.push_back(subItem);
    }
    void remove(Item* subItem) override{
        children.erase(std::remove(children.begin(),children.end(),subItem),children.end());
    }
    void display() override{
        for (auto& child : children) {
            if (ownerName != "") std::cout << ownerName << ' ' << itemName;
            child->display();
        }
    }
private:
    vector <Item*> children;
};

int main(){
    system("chcp 65001");
    Item *file = new DropDownItem("Файл->");
    Item *create = new DropDownItem("Создать->");
    Item *open = new DropDownItem("Открыть->");
    Item *exit = new ClickableItem("Выход");
    file->add(create);
    file->add(open);
    file->add(exit);
    Item *project = new ClickableItem("Проект...");
    Item *repository = new ClickableItem("Репозиторий...");
    create->add(project);
    create->add(repository);
    Item *solution = new ClickableItem("Решение...");
    Item *folder = new ClickableItem("Папка...");
    open->add(solution);
    open->add(folder);
    file->display();
    std::cout << "\n------\n";
    file->remove(create);
    file->display();
}