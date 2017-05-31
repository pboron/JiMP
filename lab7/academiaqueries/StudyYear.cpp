//
// Created by Rambo on 2017-04-09.
//

#include "StudyYear.h"

namespace academia{
    StudyYear::StudyYear(int year){
        year_ = year;
    }

    StudyYear &StudyYear::operator++() {
        ++year_;
        return *this;
    };

    StudyYear &StudyYear::operator--() {
        --year_;
        return *this;
    };

    StudyYear StudyYear::setYear(int year) {
        this->year_ = year;
    }

    StudyYear StudyYear::GetYear() const {
        return year_;
    }

    istream& operator>>(istream &in, StudyYear &year){
        std::string str;
        in >> str;
        year.setYear(atoi(str));
    }

    ostream& operator<<(ostream &out, const StudyYear &year){
        out << year.GetYear();
    }

    bool operator>(const StudyYear first, const StudyYear second){
        return (first.GetYear() > second.GetYear());
    }

    bool operator>=(const StudyYear first, const StudyYear second){
        return (first.GetYear() >= second.GetYear());
    }

    bool operator<(const StudyYear first, const StudyYear second){
        return (first.GetYear() < second.GetYear());
    }

    bool operator<=(const StudyYear first, const StudyYear second){
        return (first.GetYear() <= second.GetYear());
    }
}
