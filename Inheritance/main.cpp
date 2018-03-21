#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class Shape {
protected:
  string m_name;

public:
  Shape(string name): m_name(name) {}

  ~Shape(){}

  virtual void draw() = 0;

  void print() {
    cout << "Print from shape" << endl;
  }

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

  void print() {
    cout << "Print from Line" << endl;
  }

};

class Point: public Shape {
public:
  Point(string name): Shape(name) {}

  ~Point() {}

   virtual void draw() {
    cout << "This is drawing from " << getName() << endl;
  }

   void print() {
    cout << "Print from Point" << endl;
  }
};


int main()
{

    //Shape s("Shape"); disallowed duo to an abstract class

    auto line = std::make_shared<Line>("Line");
    auto point = std::make_shared<Point>("Point");

    line->draw();
    point->draw();

    vector<shared_ptr<Shape>> shapeList;
    shapeList.push_back(line);
    shapeList.push_back(point);

    shapeList[0]->draw();
    shapeList[1]->draw();


    shapeList[0]->print(); // none virtual function
    shapeList[1]->print(); // none virtual function

    line->print(); // function override
    point->print(); // function override

    return 0;
}
