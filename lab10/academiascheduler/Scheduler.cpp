//
// Created by Rambo on 2017-05-17.
//

#include "Scheduler.h"

namespace academia {

    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year)
            : course_id_(course_id), teacher_id_(teacher_id), room_id_(room_id), time_slot_(time_slot), year_(year) {}

    void Schedule::InsertScheduleItem(const SchedulingItem &it) {
        array_.push_back(it);
    }


    long Schedule::Size() const {
        return array_.size();
    }

    const SchedulingItem &Schedule::operator[](const int &id) const {
        return array_[id];
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule new_schedule;
        std::copy_if(this->array_.begin(),this->array_.end(),std::back_inserter(new_schedule.array_),[teacher_id](const auto &it){return it.TeacherId()==teacher_id;});
        return new_schedule;
    }

    Schedule Schedule::OfYear(int year_id) const{
        Schedule new_schedule;
        std::copy_if(this->array_.begin(),this->array_.end(),std::back_inserter(new_schedule.array_),[year_id](const auto &it){return it.Year()==year_id;});
        return new_schedule;
    }

    Schedule Schedule::OfRoom(int room_id) const{
        Schedule new_schedule;
        std::copy_if(this->array_.begin(),this->array_.end(),std::back_inserter(new_schedule.array_),[room_id](const auto &it){return it.RoomId()==room_id;});
        return new_schedule;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> v;
        int arr[n_time_slots];
        for(int i=0; i<n_time_slots;++i){
            arr[i]=i+1;
        }
        for(int i=0; i<array_.size();++i){
            if(array_[i].TimeSlot()<n_time_slots)
                arr[array_[i].TimeSlot()-1]=0;
        }
        for(int i=0; i<n_time_slots;++i){
            if(arr[i]!=0){
                v.push_back(arr[i]);
            }
        }
        return v;
    }

    Schedule PrepareNewSchedule2(const std::vector<int> &rooms,
                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                 const std::map<int, std::set<int>> &courses_of_year,
                                 int n_time_slots) {
        Schedule new_schedule;
        int arr[teacher_courses_assignment.size()][n_time_slots];
        int arr2[rooms.size()][n_time_slots];
        for(int i=0;i<teacher_courses_assignment.size();++i){
            for(int j=0; j<n_time_slots;++j){
                arr[i][j]=0;
            }
        }
        for(int i=0;i<rooms.size();++i){
            for(int j=0; j<n_time_slots;++j){
                arr[i][j]=0;
            }
        }

        auto year_it = courses_of_year.begin();
        auto course_it = year_it->second.begin();
        int flag=0;

        for(int i=1; i<=n_time_slots;++i){
            for(auto teacher_it: teacher_courses_assignment){
                for(auto teacher_course_it: teacher_it.second){
                    if(teacher_course_it==*course_it and arr[teacher_it.first-1][i-1]!=1){
                        arr[teacher_it.first/100-1][i-1]=1;
                        int room_it=0;
                        for(int j=0;j<rooms.size();++j){
                            if(arr2[j][i]!=1){
                                arr2[j][i]=1;
                                room_it=(j+1)*1000;
                                break;
                            }
                        }
                        if(room_it==0) {
                            ++i;
                            break;
                        }
                        new_schedule.InsertScheduleItem(SchedulingItem{*course_it,teacher_it.first,room_it,i,year_it->first});
                        ++i;
                        if(i>n_time_slots){
                            break;
                        }
                    }
                }
                if(i>n_time_slots){
                    break;
                }
            }
            ++course_it;
            if(course_it==year_it->second.end()){
                ++year_it;
                if(year_it==courses_of_year.end()){
                    return new_schedule;
                }
                course_it = year_it->second.begin();
            }
        }
        throw NoViableSolutionFound{"error"};
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule new_schedule;
        int arr[teacher_courses_assignment.size()][n_time_slots];
        for(int i=0;i<teacher_courses_assignment.size();++i){
            for(int j=0; j<n_time_slots;++j){
                arr[i][j]=0;
            }
        }

        auto year_it = courses_of_year.begin();
        auto course_it = year_it->second.begin();

        for(auto room_it: rooms){
            for(int i=1; i<=n_time_slots;++i){
                for(auto teacher_it: teacher_courses_assignment){
                    for(auto teacher_course_it: teacher_it.second){
                        if(teacher_course_it==*course_it){
                            if(arr[teacher_it.first-1][i-1]!=1) {
                                arr[teacher_it.first / 100 - 1][i - 1] = 1;
                                new_schedule.InsertScheduleItem(
                                        SchedulingItem{*course_it, teacher_it.first, room_it, i, year_it->first});
                                ++i;
                                if (i > n_time_slots) {
                                    break;
                                }
                            }
                            else{
                                int k=i;
                                while(arr[teacher_it.first / 100 - 1][k - 1] == 1 and k<=n_time_slots){
                                    k++;
                                }
                                if(k<=n_time_slots){
                                    new_schedule.InsertScheduleItem(
                                            SchedulingItem{*course_it, teacher_it.first, room_it, k, year_it->first});
                                }
                            }
                        }
                    }
                    if(i>n_time_slots){
                        break;
                    }
                }
                ++course_it;
                if(course_it==year_it->second.end()){
                    ++year_it;
                    if(year_it==courses_of_year.end()){
                        return new_schedule;
                    }
                    course_it = year_it->second.begin();
                }
            }
        }
        throw NoViableSolutionFound{"error"};
    }

    NoViableSolutionFound::NoViableSolutionFound(const std::string &__arg) : std::runtime_error(__arg) {}
}