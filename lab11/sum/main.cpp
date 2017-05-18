//
// Created by Student on 18.05.2017.
//

#include "Sum.h"
#include <iostream>
#include <complex>

using namespace std;

int main(){
    double result = Sum(7.3, 6.1);
    cout << result << endl;
    int result2 = Sum(3,13);
    cout << result2 << endl;
    complex<double> result3 = Sum(2.9+3i,8.6+1.5i);
    cout << result3 << endl;
    return 0;
}