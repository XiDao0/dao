#include <iostream>
#include <string>
using namespace std;

class Person{
    friend ostream & operator<<(ostream &out, Person &p);
public:
    Person& operator--(){
        --m;
        return *this;
    }
    Person operator--(int){
        Person temp = *this;
        m--;
        return temp;
    }
    Person(int a){
        prt = new int(a);
    }
    bool operator ==(Person &p){
        if(p.m == this->m){
            return true;
        }
        return false;
    }
    Person& operator=(Person &p){
        if(prt != NULL){
            delete prt;
            prt = NULL;
        }
        prt = new int(*p.prt);
        return *this;
    }
    ~Person(){
        if(prt != NULL){
            delete prt;
            prt = NULL;
        }
    }
//    Person(int a, int b){
//        this->m_a = a;
//        this->m_b = b;
//    }

private:
    int m = 2;
    int *prt;
    int m_a;
    int m_b;
};

ostream& operator<<(ostream &out, Person &p){
    out << *p.prt;
    return out;
}

void test(){
    Person p(18);
    Person p2(20);
    Person p3(30);
    p = p2 = p3;
    cout << p << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    if( p == p2){
        cout << "do better" << endl;
    }else{
        cout << "false" << endl;
    }
//    cout << --p <<endl;
//    cout << p-- << endl;
//    cout << p << endl;

}

int main() {
    test();

    return 0;
}
