//
// Created by Rambo on 2017-06-05.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <functional>

namespace academia{
    class TeacherId{
    public:
        TeacherId(int id);
        TeacherId();
        //int Id();
        operator int() const;
    private:
        int id_;
    };

    class Teacher{
    public:
        Teacher(TeacherId id, std::string name,std::string place);
        TeacherId Id() const;
        std::string Name() const;
        std::string Department() const;
        bool operator!=(const Teacher teacher) const;
        bool operator==(const Teacher teacher) const;
    private:
        std::string name_;
        std::string place_;
        TeacherId id_;


    };
    class TeacherHash{
    public:
        TeacherHash(){};
        size_t operator()(const Teacher &teacher) const;
    private:

    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
