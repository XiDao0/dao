#include <iostream>
#include <string>
using namespace std;


class AbstractDrink{
public:
    virtual void Boil() = 0;
    virtual void Put() = 0;
    virtual void Stir() = 0;
    virtual void Other() = 0;
    void Sum(){
        Boil();
        Put();
        Stir();
        Other();
    }
};

class Milk:public AbstractDrink{
public:
    virtual void Boil(){
           cout << "烧水" <<endl;
    }
    virtual void Put(){
        cout <<"放入牛奶"<<endl;
    }
    virtual void Stir(){
        cout << "搅拌" << endl;
    }
    virtual void Other(){
        cout << "加入佐料"<<endl;
    }
};

class Tea:public AbstractDrink{
public:
    virtual void Boil(){
        cout << "烧水" <<endl;
    }
    virtual void Put(){
        cout <<"放入茶叶"<<endl;
    }
    virtual void Stir(){
        cout << "搅拌" << endl;
    }
    virtual void Other(){
        cout << "加入枸杞"<<endl;
    }
};

void dowork(AbstractDrink *abs){
    abs->Sum();
    delete abs;
}

void test(){
    dowork(new Tea);
    cout<<"---------------------"<<endl;
    dowork(new Milk);
}

int main() {
    test();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
