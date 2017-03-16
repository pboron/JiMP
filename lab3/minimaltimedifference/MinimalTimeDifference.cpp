//
// Created by Student on 16.03.2017.
//

#include "MinimalTimeDifference.h"
namespace minimaltimedifference {
    using namespace std;

    unsigned int ToMinutes(std::string time_HH_MM) {
        int h, m;
        regex pattern{R"((\d{1,2}):(\d{2}))"};
        string line(time_HH_MM);
        smatch matches;
        if (regex_match(line, matches, pattern)) {
            h = std::stoi(matches[1]);
            m = std::stoi(matches[2]);
        }
        int time = (60 * h) + m;
        return time;
    }

   unsigned int MinimalTimeDifference(std::vector<std::string> times) {
        int i = 0, dif, min = 720;
        const int maximal_time = 1440;
        int Size = times.size();
        int *tab = new int[Size];
        for (std::string v : times) {
            tab[i] = ToMinutes(v);
            ++i;
        }
        for (i=0;i<Size;++i) {
            for (int j=i+1;j<Size;++j) {
                if (tab[i] - tab[j] < 0) {
                    dif = tab[j] - tab[i];
                }
                else{
                    dif = tab[i] - tab[j];
                }
                if (dif > maximal_time/2) {
                    dif = maximal_time - dif;
                }
                if (dif < min) {
                    min = dif;
                }
            }
        }
        delete tab;
        return min;
    }
}