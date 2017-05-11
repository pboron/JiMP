//
// Created by Rambo on 2017-05-08.
//

#ifndef EXERCISES_MOVIESUBTITLES_H
#define EXERCISES_MOVIESUBTITLES_H

#include <sstream>
#include <regex>
#include <stdexcept>

namespace moviesubs{
    class MovieSubtitles{
    public:
        virtual void ShiftAllSubtitlesBy(int, int, std::stringstream*, std::stringstream*)=0;
    };

    class MicroDvdSubtitles: public MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(int, int, std::stringstream*, std::stringstream*);
    };

    class SubRipSubtitles: public MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(int, int, std::stringstream*, std::stringstream*);
    private:
        bool ValidateTimes(std::smatch);
    };

    class NegativeFrameAfterShift: public std::runtime_error{
    public:
        NegativeFrameAfterShift() = delete;
        NegativeFrameAfterShift(std::string str):std::runtime_error(str){};
    };

    class SubtitleEndBeforeStart: public std::runtime_error{
    public:
        SubtitleEndBeforeStart() = delete;
        SubtitleEndBeforeStart(std::string str, int l):std::runtime_error("At line " + std::to_string(l) + ": " +
                                                                          str),line_(l){};
        int LineAt () const {return line_;}
    private:
        int line_;
    };

    class InvalidSubtitleLineFormat: public std::runtime_error{
    public:
        InvalidSubtitleLineFormat()=delete;
        InvalidSubtitleLineFormat(std::string str): std::runtime_error(str){};
    };

    class MissingTimeSpecification: public std::runtime_error{
    public:
        MissingTimeSpecification()=delete;
        MissingTimeSpecification(std::string str): std::runtime_error(str){};
    };

    class OutOfOrderFrames: public std::runtime_error{
    public:
        OutOfOrderFrames() = delete;
        OutOfOrderFrames(std::string str): std::runtime_error(str){};
    };

}

#endif //EXERCISES_MOVIESUBTITLES_H
