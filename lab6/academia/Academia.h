//
// Created by Student on 06.04.2017.
//

#ifndef JIMP_EXERCISES_ACADEMIA_H
#define JIMP_EXERCISES_ACADEMIA_H
#include <string>
namespace academia {

    class StudyYear {
    public:
        StudyYear();
        StudyYear(int year);
        ~StudyYear();

        StudyYear &operator++(){
            year_ = year_ + 1;
            return *this;
        }
        StudyYear &operator--(){
            year_ = year_ - 1;
            return *this;
        }
    private:
        int year_;
    };

    class Student {
    public:
        Student();
        Student(std::string id, std::string first_name, std::string last_name, std::string program, StudyYear year);
        ~Student();

    private:
        std::string id_, first_name_, last_name_, program_;
        StudyYear year_;
    };
}

std::istream& operator>>(std::istream &is, StudyYear& year);

std::ostream& operator<<(std::ostream &is, const StudyYear& year);
#endif //JIMP_EXERCISES_ACADEMIA_H
