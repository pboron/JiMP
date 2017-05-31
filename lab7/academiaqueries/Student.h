//
// Created by Rambo on 2017-04-09.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include <string>
#include "StudyYear.h"

using ::std::string;
using ::std::istream;
using ::std::ostream;

namespace academia{
    class Student{
    public:
        Student();
        Student(string id, string first, string last, string program, int year);
        void setId(string id);
        void setFirstName(string first_name);
        void setLastName(string last_name);
        void setProgram(string program);
        void setStudyYear(int study_year);
        string getId() const;
        string getFirstName() const;
        string getLastName() const;
        string getProgram() const;
        StudyYear getStudyYear() const;

        friend istream& operator>>(istream &in, Student &s);
    private:
        std::string id_, first_name_, last_name_, program_;
        StudyYear study_year_;
    };
    istream &operator>>(istream &in, Student &student);
    ostream &operator<<(ostream &out, const Student &student);
    bool operator==(const Student firststudent, const Student secondstudent);
    bool operator==(const Student firststudent, string id_str);
    bool operator<(const Student firststudent, const Student secondstudent);
}

#endif //JIMP_EXERCISES_STUDENT_H
