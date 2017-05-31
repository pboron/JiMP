//
// Created by Student on 18.05.2017.
//

#ifndef JIMP_EXERCISES_MEAN_H
#define JIMP_EXERCISES_MEAN_H

#include <vector>

template<class T>
T Mean(std::vector<T> v){
    T sum = T();
    for(T u:v){
        sum += u;
    }
    T n = v.size();
    return (sum/n);
}

#endif //JIMP_EXERCISES_MEAN_H
