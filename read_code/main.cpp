#include <iostream>

using namespace std;

class Bomb {
    int x;
public:
    Bomb() : x(0) {}

    ~Bomb() { //throw "boom";
    }


    void * operator new(size_t n) throw() {
        cout << "Operator new called" << endl;
        return malloc(n);
    }

    void operator delete(void *p) throw() {
        cout << "Operator delete called" << endl;
        if (p != 0) free(p);
    }
};


void f(){
    Bomb myBomb;

    Bomb *pb = new Bomb();

    try{
        delete pb;
    }catch(...){
        cout << "catch exception" << endl;

    }
    throw "no bomb";
}


int main()
{
    try{
        f();
    }catch (char* msg){
        cout << "f throws " << msg << endl;
    }catch(...){
        cout << "catch all" << endl;

    }

    return 0;
}
