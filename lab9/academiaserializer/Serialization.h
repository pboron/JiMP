//
// Created by Student on 04.05.2017.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <iostream>
#include <functional>
#include <vector>

namespace academia{

    class Serializer;

    class Serializable{
    public:
        virtual void Serialize(Serializer *) const=0;

    };

    class Serializer{
    public:
        Serializer(std::ostream *out):out_(out){};

        virtual void Separate(){(*out_)<<"";};

        virtual void IntegerField(const std::string &field_name, int value) =0;
        virtual void DoubleField(const std::string &field_name, double value) =0;
        virtual void StringField(const std::string &field_name, const std::string &value) =0;
        virtual void BooleanField(const std::string &field_name, bool value) =0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) =0;
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name) =0;
        virtual void Footer(const std::string &object_name) =0;

    protected:
        std::ostream *out_;
    };

    class Room: public Serializable{
    public:
        enum class Type{
            COMPUTER_LAB,
            CLASSROOM,
            LECTURE_HALL
        };

        Room(int id, const std::string &name, Room::Type type);

        void Serialize(Serializer *serializer) const override;

    private:
        std::string TypeToString(const Type &type) const{
            switch (type){
                case Type::CLASSROOM:
                    return "CLASSROOM";
                case Type::LECTURE_HALL:
                    return "LECTURE_HALL";
                case Type::COMPUTER_LAB:
                    return "COMPUTER_LAB";

            }
        }

        std::string name_;
        int id_;
        Type type_;
    };

    class Building: public Serializable{
    public:
        Building(int id, const std::string &name, const std::vector<Room> &rooms);
        void Serialize(Serializer *serializer) const override;
    private:
        std::string name_;
        int id_;
        std::vector<Room> rooms_;
    };

    class XmlSerializer: public Serializer{
    public:
        XmlSerializer(std::ostream *out):Serializer(out){};
        void IntegerField(const std::string &field_name, int value) override {
            (*out_) << "<" << field_name << ">" << value << "<\\" <<  field_name <<">";
        };
        void DoubleField(const std::string &field_name, double value) override{};
        void StringField(const std::string &field_name, const std::string &value)override{
            (*out_) << "<" << field_name << ">" << value << "<\\" <<  field_name <<">";
        };
        void BooleanField(const std::string &field_name, bool value) override{};
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override{
            (*out_)<< "<" << field_name << ">";
            value.Serialize(this);
            (*out_)<< "<\\" << field_name << ">";
        };
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override{};
        void Header(const std::string &object_name) override{
            (*out_) << "<" << object_name << ">";
        };
        void Footer(const std::string &object_name) override{
            (*out_) << "<\\" << object_name << ">";
        };
    };

    class JsonSerializer: public Serializer{
    public:
        JsonSerializer(std::ostream *out):Serializer(out){};
        void IntegerField(const std::string &field_name, int value) override {
            (*out_) << "\"" << field_name << "\": " << value;
        };
        void DoubleField(const std::string &field_name, double value) override{};
        void StringField(const std::string &field_name, const std::string &value)override{
            (*out_) << "\"" << field_name << "\": " << "\""<< value << "\"";
        };
        void BooleanField(const std::string &field_name, bool value) override{};
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override{
            value.Serialize(this);
        };
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override{};
        void Header(const std::string &object_name) override{
            if(object_name=="building" or object_name == "room")
                (*out_) << "{";
            if(object_name=="rooms")
                (*out_) << "\"rooms\": [";
        };
        void Footer(const std::string &object_name) override{
            if(object_name=="building" or object_name == "room")
                (*out_) << "}";
            if(object_name=="rooms")
                (*out_) << "]";
        };

        void Separate() override {(*out_) << ", ";};
    };

}


#endif //JIMP_EXERCISES_SERIALIZATION_H