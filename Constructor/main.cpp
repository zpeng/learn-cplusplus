#include <iostream>

using namespace std;

class Base {
public:
    Base() { cout << "Default C'tor" << endl; }
    ~Base() { cout << "Default D'tor" << endl; }

    Base(const Base &b) {
        cout << "Copy C'tor" << endl;
    }

    Base(Base &&b) {
        cout << "Move C'tor" << endl;
    }

    Base& operator= (const Base&){
        cout << "Copy operator" << endl;
        return *this; // just for demo purpose
    }

    Base& operator= (Base&&) {
        cout << "Move operator" << endl;
        return *this; // just for demo purpose
    }
};

Base returnBaseByValue() {
  return Base();
}

int main()
{
    //Base b; // calls default c'tor / d'tor

    //Base b = Base();   // calls default c'tor / d'tor

    //Base A;
    //Base B(A); // C'tor Copy C'tor d'tor d'tor

    //Base A; // C'tor
    //Base B; // C'tor
    //A = B;  // copy assignment, d'tor d'tor

    //Base A = returnBaseByValue(); // C'tor d'tor,  RVO happens here

    //Base A(returnBaseByValue()); // C'tor d'tor,  RVO happens here


    //Base A;
    //A = returnBaseByValue();  // C'tor  C'tor move operator d'tor d'tor,  using the move operator


    return 0;
}
