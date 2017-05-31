//
// Created by Rambo on 2017-04-09.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H

#include <string>

using ::std::istream;
using ::std::ostream;

namespace academia {
    class StudyYear {
    public:
        StudyYear(int year);
        StudyYear &operator++();
        StudyYear &operator--();
        StudyYear setYear(int year);
        StudyYear etYear() const;
        friend istream &operator>>(istream &in, StudyYear &year);
    private:
        int year_;
    };
    istream &operator>>(istream &in, StudyYear &year);
    ostream &operator<<(ostream &out, const StudyYear &year);
    bool operator>(const StudyYear firstperson, const StudyYear secondperson );
    bool operator>=(const StudyYear firstperson, const StudyYear secondperson );
    bool operator<(const StudyYear firstperson, const StudyYear secondperson );
    bool operator<=(const StudyYear firstperson, const StudyYear secondperson );
}

#endif //JIMP_EXERCISES_STUDYYEAR_H