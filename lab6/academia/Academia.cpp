//
// Created by Student on 06.04.2017.
//

#include "Academia.h"
#include <iostream>
#include <iomanip>
#include <string>

namespace academia{
    using ::std::istream;
    using ::std::ws;
    using ::std::ostream;
    using ::std::endl;
    using ::std::cout;

    StudyYear::StudyYear() : year_(0) {
        cout << "Konstruktor bezparametrowy" << endl;
    }

    StudyYear::StudyYear(int year) {
        cout << "Konstruktor parametrowy" << endl;
        year_ = year;
    }

    StudyYear::~StudyYear() {
        cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
        cout << endl;
    }

    Student::Student(std::string id, std::string first_name, std::string last_name, std::string program) {
        cout << "Konstruktor parametrowy" << endl;
        id_ = id;
        first_name_ = first_name;
        last_name_ = last_name;
        program_ = program;
    }

    Student::~Student() {
        cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
        cout << endl;
    }

    void Student::SetID(std::string id) {
        this->id_ = id;
    }

    void Student::SetFirstName(std::string first_name) {
        this->first_name_ = first_name;
    }

    void Student::SetLastName(std::string last_name) {
        this->last_name_ = last_name;
    }

    void Student::SetProgram(std::string program) {
        this->program_ = program;
    }

    void StudyYear::SetYear(int year) {
        this->year_ = year;
    }

    double ReadNumber(istream* is) {
        double d;
        (*is) >> d;
        return d;
    }

    std::string ReadString(istream* is) {
        string d;
        (*is) >> d;
        return d;
    }

    istream& operator>>(istream & input, StudyYear& y){
        y.StudyYear(ReadNumber(&input));
        return input;
    }

    ostream& operator<<(ostream &out, const StudyYear& y){
        out << y.year_ << std::endl;
    }

    istream& operator>>(istream & input, Student& s){
        CheckNextChar('{', &input);
        s.SetID(ReadString(&input));
        CheckNextChar(',', &input);
        IgnoreWhitespace(&input);
        s.SetFirstName(ReadString(&input));
        CheckNextChar(',', &input);
        IgnoreWhitespace(&input);
        s.SetLastName(ReadString(&input));
        CheckNextChar(',', &input);
        IgnoreWhitespace(&input);
        s.SetProgram(ReadString(&input));
        CheckNextChar(',', &input);
        IgnoreWhitespace(&input);
        CheckNextChar('}', &input);
        return input;      // Umożliwia cin >> a >> b >> c;
    }

    ostream& operator<<(ostream &out, const Student& s){
        out << "{" << s.id_ << "," << s.first_name_ << "," << s.last_name_ << "," << s.program_ << "}" << std::endl;
    }
}