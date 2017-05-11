//
// Created by Student on 11.05.2017.
//

#include "Algo.h"

namespace algo{
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out){
        std::copy_n(v.begin(), n_elements, std::back_inserter(*out));
    }
    bool Contains(const std::vector<int> &v, int element){

    }
    void InitializeWith(int initial_value, std::vector<int> *v){

    }
    std::vector<int> InitializedVectorOfLength(int length, int initial_value){

    }
    std::vector<std::string> MapToString(const std::vector<double> &v){

    }
}
