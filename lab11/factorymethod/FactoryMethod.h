//
// Created by Student on 18.05.2017.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>

namespace factoryMethod{

    class MyType{
    public:
        std::string SayHello{
             return "hello";
        };
    };

    template<class T>
    T Create() {
        return new T;
    };
}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
