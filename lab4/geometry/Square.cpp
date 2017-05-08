//
// Created by Student on 23.03.2017.
//

#include <memory>
#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>
#include "Point.h"
#include "Square.h"

namespace geometry{
    using ::std::ostream;
    using ::std::endl;
    using ::std::cout;
    using ::std::pow;
    using ::std::sqrt;

    Square::Square(double Circumference, double Area) {
        cout << "Konstruktor parametrowy" << endl;
        Circumference_ = Circumference;
        Area_ = Area;
    }

    int S(Point p1, Point p2, Point p3, Point p4) {


        class Square s1(0, 0);

        double o1, o2, o3, o4;
        o1 = p2.Distance(p1);
        o2 = p3.Distance(p2);
        o3 = p4.Distance(p3);
        o4 = p1.Distance(p4);

        if (o1 == o2 && o2 == o3 && o3 == o4) {
            s1.Circumference = 4 * o1;
            s1.Area = (double) o1^2;
        }
        return s1;
    }

}