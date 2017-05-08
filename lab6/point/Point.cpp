//
// Created by Student on 06.04.2017.
//

#include "Point.h"
#include <iomanip>
#include <iostream>

using ::std::istream;
using ::std::ws;
using ::std::ostream;
using ::std::endl;
using ::std::cout;


/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
Point::Point() : x_(0), y_(0) {
    cout << "Konstruktor bezparametrowy" << endl;
}

Point::Point(double x, double y) {
    cout << "Konstruktor parametrowy" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point() {
    cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
    cout << endl;
}


void Point::SetX(double x) {
    this->x_ = x;
}

void Point::SetY(double y) {
    this->y_ = y;
}

//Helper functions:
void CheckNextChar(char c, istream* is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw std::runtime_error("invalid character");
    }
    is->ignore();
}

void IgnoreWhitespace(istream* is) {
    (*is) >> ws;
}

double ReadNumber(istream* is) {
    double d;
    (*is) >> d;
    return d;
}


// Właściwa definicja, obydwa argumenty funkcji nie
//są zadeklarowane jako const, bo obydwa są modyfikowane
//wewnątrz funkcji (STL nie używa naszej konwencji z przekazywaniem
//przez wskaźnik)
istream& operator>>(istream & input, Point& p){
    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;      // Umożliwia cin >> a >> b >> c;
}

ostream& operator<<(ostream &out, const Point& p){
    out << "(" << p.x_ << "," << p.y_ << ")" << std::endl;
}