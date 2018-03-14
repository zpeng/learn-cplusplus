#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
  string m_name;

public:
  Shape(string name): m_name(name) {}

  ~Shape(){}

  virtual void draw() = 0;

  string getName() {
    return m_name;
  }
};

class Line: public Shape {
public:

  Line(string name): Shape(name) {}

  ~Line() {}

  virtual void draw() {
    cout << "This is drawing from " << getName() << endl;
  }

};

class Point: public Shape {
public:
  Point(string name): Shape(name) {}

  ~Point() {}

  virtual void draw() {
    cout << "This is drawing from " << getName() << endl;
  }
};