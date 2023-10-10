#include <iostream>
using  namespace std;
#include <string>

class basic{
public:
    virtual void head(){
        cout << "base:head"<< endl;
    }
    void body(){
        cout<<"body"<<endl;
    }
    void foot(){
        cout << "foot" << endl;
    }
    int a;
protected:
    int c;
private:
    int b;
};
class person1 : public basic{
public:
    void head(){
        cout << "son:head"<< endl;
    }
};

void Dospeak(basic &base){
    base.head();
}

void test(){
    person1 p1;
    Dospeak(p1);
    p1.basic::head();
}

int main() {
    test();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
