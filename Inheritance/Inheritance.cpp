// Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shape.cpp"
#include <memory>
#include <vector>

int _tmain(int argc, _TCHAR* argv[])
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

  int i ;
  cin >> i ;

	return 0;
}

