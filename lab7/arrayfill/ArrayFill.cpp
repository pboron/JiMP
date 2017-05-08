//
// Created by Student on 20.04.2017.
//

#include "ArrayFill.h"

namespace arrays{
    void FillArray(size_t size, const Filler &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.fill(i));
        }
    }

    int IncrementalFill::fill(int index) const {
        return (value_b_+index*value_a_);
    }
}