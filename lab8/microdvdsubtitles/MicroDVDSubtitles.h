//
// Created by Rambo on 2017-05-08.
//

#ifndef EXERCISES_MICRODVDSUBTITLES_H
#define EXERCISES_MICRODVDSUBTITLES_H

#ifndef JIMP_EXERCISES_MICRODVDSUBTITLES_H
#define JIMP_EXERCISES_MICRODVDSUBTITLES_H

#include <sstream>
#include <regex>
#include <stdexcept>

namespace subtitles{
    class MovieSubtitles{
    public:
        virtual void ShiftSubtitlesBy(std::stringstream*, std::stringstream*, int, int)=0;
    };

    class MicroDVDSubtitles: public MovieSubtitles{
    public:
        void ShiftSubtitlesBy(std::stringstream*, std::stringstream*, int, int);
    };

    class SubRipSubtitles: public MovieSubtitles{
    public:
        void ShiftSubtitlesBy(std::stringstream*, std::stringstream*, int, int);
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

#endif //EXERCISES_MICRODVDSUBTITLES_H
