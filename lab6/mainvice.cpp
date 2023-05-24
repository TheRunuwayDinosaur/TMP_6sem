#include <bits/stdc++.h>
#include <windows.h>
#include <Windows.h>

using namespace std;

class ISite{
public:
    virtual string getPage(int num) = 0;
    virtual ~ISite() = default;
};

string cast_to_str(int x){
    string res = "";
    while(x > 0){
        res += char((x % 10) + '0');
        x /= 10;
    }
    reverse(res.begin(),res.end());
    return res;
}

class Site : public ISite{
public:
    string getPage(int num) override{
        string page = "Это страница сайта - " + cast_to_str(num);
        return page;
    }
};

class SiteProxy : public ISite{
public:
    SiteProxy(ISite* site) : site(site){

    }
    ~SiteProxy(){
        delete site;
    }
    string getPage(int num) override{
        string page;
        if (cache.find(num) == cache.end()){
            page = site->getPage(num);
            cache[num] = page;
        }
        else{
            page = cache[num];
            page.insert(0,"из кэша: ");
        }
        return page;
    }
private:
    ISite *site;
    map <int,string> cache;
};

int main(){
    system("chcp 65001");
    ISite *mySite = new SiteProxy(new Site());
    std::cout << mySite->getPage(1) << "\n";
    std::cout << mySite->getPage(2) << "\n";
    std::cout << mySite->getPage(3) << "\n";
    std::cout << mySite->getPage(2);
}