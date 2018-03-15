// Constructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Base {
public:
  Base(){ cout << "Call Base" << endl;}
};

class A: public Base {
public:
  A() { cout << "Call A" << endl; }
};

class C {
public:
  C() { cout << "Call C" << endl; }

};
class B: public A {
public:
  B() { cout << "Call B" << endl; }

private:
  C c;
};


class MyClass {
public:

  // default constructor
  MyClass() {
    cout << "Call Default Constructor" << endl;
  }

  ~MyClass() {
    cout << "Call Destructor" << endl;
  }

  MyClass(const MyClass &o) {
    cout << "Call Copy Constructor" << endl;
  }

  MyClass& operator= (MyClass& o){
    cout << "Call Copy assignment" << endl;
    return o;
  }
};

MyClass getMyClassByValue() {
  MyClass c;
  return c;
}

int _tmain(int argc, _TCHAR* argv[])
{

  A a;

  cout << endl;

  /*
  Call order will be 
  first the class's base construct up to itself
  Then if there is member variable, initilise them 
  Then call its own constructor
  */

  B b;
  cout << endl << endl;

  MyClass mc; // call defualt constructor
  cout << endl;
  
  MyClass mc2(mc); // call copy constructor
  cout << endl;
  
  MyClass mc3 = getMyClassByValue(); // call copy constructor
  cout << endl;
  
  MyClass mc4;
  mc4 = getMyClassByValue();
  cout << endl;

  int i;
  cin >> i;
	return 0;
}

