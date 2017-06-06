//
// Created by Student on 25.05.2017.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <ctime>
#include <utility>
using namespace std::chrono;
namespace profiling{
    template <class ResultType>
    auto TimeRecorder(ResultType method){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        auto result = method();
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double,std::milli> time_span = duration_cast<duration<double>>(t2 - t1);
        return std::pair<decltype(result),double>(result,time_span.count());
    };

}

#endif //JIMP_EXERCISES_TIMERECORDER_H
