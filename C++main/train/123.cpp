#include <iostream>
using namespace std;
#include <string>

class Buding{
    friend void goodgay(Buding & b);
public:
    Buding(){
        this->Bedroom = "卧室";
        this->Dilingroom = "客厅";
    }
public:
    string Bedroom;
private:
    string Dilingroom;
};

void goodgay(Buding & b){
    b.Bedroom = "卧室2";
    cout<< b.Bedroom << endl;
    cout<< b.Dilingroom;
}
void test(){
    Buding b;
    goodgay(b);
}

int main(){
    test();

    return 0;
}