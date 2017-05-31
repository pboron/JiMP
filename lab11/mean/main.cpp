//
// Created by Student on 18.05.2017.
//

#include "Mean.h"
#include <iostream>
#include <complex>

using namespace std;

int main(){
    vector<int> v1 {4, 23, 99, -12};
    int mean1 = Mean(v1);
    cout << mean1 << endl;
    vector<double> v2 {3.8, 15.2, 63.9, -20.7};
    double mean2 = Mean(v2);
    cout << mean2 << endl;
    vector<complex<double>> v3 {2.3+3.2i, 10.8+0.2i, 24.9+2i, 71.6+42.9i};
    complex<double> mean3 = Mean(v3);
    cout << mean3 << endl;
    return 0;
}