//
// Created by Student on 11.05.2017.
//

#include "Algo.h"
#include <iostream>

namespace algo{
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out){
        std::copy_n(v.begin(), n_elements, std::back_inserter(*out));
    }
    bool Contains(const std::vector<int> &v, int element){

    }
    void InitializeWith(int initial_value, std::vector<int> *v){
        std::fill ((*v).begin(),(*v).end(),initial_value);
    }
    std::vector<int> InitializedVectorOfLength(int length, int initial_value){
        std::vector<int> v;
        std::fill_n (v.begin(),length,initial_value);
        return v;
    }
    std::vector<std::string> MapToString(const std::vector<double> &v){
        std::vector<std::string> s;
        std::move(v.begin(), v.end(), s.begin());
        return s;
    }
}
