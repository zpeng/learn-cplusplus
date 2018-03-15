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



int _tmain(int argc, _TCHAR* argv[])
{

  A a;

  cout << endl << endl;

  /*
  Call order will be 
  first the class's base construct up to itself
  Then if there is member variable, initilise them 
  Then call its own constructor
  */

  B b;
 
  int i;
  cin >> i;
	return 0;
}

