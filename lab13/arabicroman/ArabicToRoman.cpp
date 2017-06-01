//
// Created by Student on 01.06.2017.
//

#include "ArabicToRoman.h"
#include <string>

using namespace std;

string ArabicToRoman(int arabic){
    if (arabic < 1 || arabic > 3999){
        return "ERROR";
    }
    int x;
    string roman = "";
    for (int i=0; i<(arabic/1000); ++i) {
        roman = roman + "M";
    }
    arabic = arabic%1000;
    if (arabic > 899){
        roman = roman + "C" + "M";
        arabic = arabic - 900;
    }
    else{
        if (arabic > 499){
            roman = roman + "D";
            arabic = arabic - 500;
        }
        if (arabic > 399){
            roman = roman + "C" + "D";
            arabic = arabic - 400;
        }
        else{
            if (arabic > 99){
                for (int i=0; i<(arabic/100); ++i) {
                    roman = roman + "C";
                }
                arabic = arabic%100;
            }
        }
    }
    if (arabic > 89){
        roman = roman + "X" + "C";
        arabic = arabic - 90;
    }
    else{
        if (arabic > 49){
            roman = roman + "L";
            arabic = arabic - 50;
        }
        if (arabic > 39){
            roman = roman + "X" + "L";
            arabic = arabic - 40;
        }
        else{
            if (arabic > 9){
                for (int i=0; i<(arabic/10); ++i) {
                    roman = roman + "X";
                }
                arabic = arabic%10;
            }
        }
    }
    if (arabic == 9){
        roman = roman + "I" + "X";
        arabic = 0;
    }
    else{
        if (arabic > 5){
            roman = roman + "V";
            arabic = arabic - 5;
        }
        if (arabic == 4){
            roman = roman + "I" + "V";
            arabic = 0;
        }
        if (arabic > 0){
            for (int i=0; i<arabic; ++i) {
                roman = roman + "I";
            }
            arabic = 0;
        }
    }
    if(arabic == 0){
        return roman;
    }
    else{
        return "ERROR";
    }
}