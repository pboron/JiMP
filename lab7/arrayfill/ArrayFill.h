//
// Created by Student on 20.04.2017.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <iostream>
#include <string>
#include <vector>

namespace arrays{

    class Filler{
    public:
        virtual int fill(int index) const =0;
    };


    class IncrementalFill : public Filler {
    public:
        IncrementalFill(int val):value_b_(val), value_a_(1) {};
        IncrementalFill(int val_a, int val_b):value_a_(val_a), value_b_(val_b){};
        virtual int fill(int index) const override;
    private:
        int value_a_;
        int value_b_;
    };

    void FillArray (int t, Filler &f, std::vector<int> *vs);
}


#endif //JIMP_EXERCISES_ARRAYFILL_H
