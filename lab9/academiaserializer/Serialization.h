//
// Created by Student on 04.05.2017.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <memory>
#include <vector>

using namespace std;
using namespace std::literals;

namespace academia{

    class Serializer;

    class Serializable{
    public:
        virtual void Serialize(Serializer *) = 0;
    };

    class Serializer{
    public:
        Serializer(std::ostream *out):  out_(out){};
        virtual void IntegerField(const std::string &field_name, int value) = 0;
        virtual void DoubleField(const std::string &field_name, double value) = 0;
        virtual void StringField(const std::string &field_name, const std::string &value) = 0;
        virtual void BooleanField(const std::string &field_name, bool value) = 0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) = 0;
        virtual void ArrayField(const std::string &field_name, const vector<reference_wrapper<const academia::Serializable>> &value) = 0;
        virtual void Header(const std::string &object_name) = 0;
        virtual void Footer(const std::string &object_name) = 0;

    protected:
        std::ostream *out_;
    };


    class Room : public Serializable{
    public:
        enum class Type{
            CLASSROOM,
            COMPUTER_LAB,
            LECTURE_HALL
        };

        Room(int id_, const string &name_, Type type_);

        void Serialize(Serializer *ser) override;

    private:
        int id_;
        string name_;
        Type type_;
    };


}

#endif //JIMP_EXERCISES_SERIALIZATION_H
