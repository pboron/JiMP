//
// Created by Student on 06.04.2017.
//

#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point {
public:
    //Konstruktor bezparametrowy
    Point();

    //Konstruktor parametrowy
    Point(double x, double y);

    //Destruktor wykonywany przed zwolnieniem pamięci
    ~Point();

    //Metody nie modyfikujące stanu obiektu (const na końcu metody)
    //nie mogą zmodyfikować tego obiektu.
    void ToString(std::ostream *out) const;

    double Distance(const Point &other) const;

    void SetX(double x);
    void SetY(double y);

    //opcjonalna definicja pozwalająca na uzyskanie
    //dostępu do prywatnych pól z wewnątrz definicji
    //funkcji zadeklarowanej poniżej
    friend std::istream& operator>>(std::istream &, Point&);

    friend std::ostream& operator<<(std::ostream &, const Point&);

private:
    double x_, y_;
};

//właściwa deklaracja, przeciążająca
//operator >> dla strumienia wejściowego
//i klasy punkt
std::istream& operator>>(std::istream &is, Point& point);

std::ostream& operator<<(std::ostream &is, const Point& point);
#endif