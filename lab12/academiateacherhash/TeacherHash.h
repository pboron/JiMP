//
// Created by Rambo on 2017-06-05.
//



#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <utility>

namespace academia {
    class TeacherId{
    public:
        TeacherId(const int &id):id_(id){}
        TeacherId(const TeacherId &teacher):id_(teacher.id_){}
        operator int() const {return id_;};
        bool operator!=(const TeacherId &teacher) const{return teacher.id_ != id_;};
    private:
        size_t id_;
    };

    class Teacher {
    public:
        Teacher(const TeacherId &id, const std::string &name, const std::string &department):id_(id),name_(name),department_(department){}
        bool operator==(const Teacher &teacher) const {return (id_ == teacher.id_
                                                               && name_ == teacher.name_ && department_ == teacher.department_);}
        bool operator!=(const Teacher &teacher) const {return !(*this == teacher); }
        const int Id() const{ return id_;}
        const std::string Name() const{ return name_;}
        const std::string Department() const{return department_;}
    private:
        TeacherId id_;
        std::string name_, department_;
    };

    class TeacherHash{
    public:
        size_t operator()(const Teacher& in) const {
            size_t name_result = 0, department_result = 0;
            for (auto &character : in.Name()) {
                name_result += character;
            }
            for (auto &character :in.Department()) {
                department_result += character;
            }
            return in.Id() ^ department_result ^ name_result;
        }
    };
}
#endif //JIMP_EXERCISES_TEACHERHASH_H
