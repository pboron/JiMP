//
// Created by Rambo on 2017-05-17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <exception>

namespace academia{

    class SchedulingItem{
    public:
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);

        int CourseId() const {return course_id_;}
        int TeacherId() const { return teacher_id_;}
        int RoomId() const { return room_id_;}
        int TimeSlot() const {return time_slot_;}
        int Year() const { return year_;}

    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };

    class Schedule{
    public:
        ~Schedule(){array_.clear();}
        void InsertScheduleItem(const SchedulingItem &);
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfYear(int year_id) const;
        Schedule OfRoom(int room_id) const;
        long Size() const;
        const SchedulingItem &operator[](const int &id) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
    private:
        std::vector<SchedulingItem> array_;
    };

    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    };

    class GreedyScheduler: public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;
    };

    class NoViableSolutionFound:public std::runtime_error{
    public:
        NoViableSolutionFound(const std::string &__arg);
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H