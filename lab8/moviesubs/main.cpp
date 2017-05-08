//
// Created by Rambo on 2017-05-08.
//

#include "MovieSubtitles.h"
#include <iostream>

using namespace moviesubs;

int main(){
    MicroDvdSubtitles s;
    std::stringstream in {"{10}{200}JAKIS\n{260}{300}NAPIS\n"};
    std::stringstream out;
    s.ShiftAllSubtitlesBy(1400, 10, &in, &out);
    return 0;
}