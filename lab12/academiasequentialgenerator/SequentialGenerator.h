//
// Created by Rambo on 2017-06-05.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

#include <utility>

template <class TId, class TCounter>
class SequentialIdGenerator {
public:
    SequentialIdGenerator():counter_(0), first_(true) { }
    SequentialIdGenerator(const TCounter & in): counter_(in), first_(true) { }
    TId NextValue();
private:
    bool first_;
    TCounter counter_;
};
template <class TId, class TCounter>
TId SequentialIdGenerator<TId, TCounter>::NextValue() {
    if(!first_){
        ++counter_;
    }
    first_=false;

    return TId(counter_);
}

#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H