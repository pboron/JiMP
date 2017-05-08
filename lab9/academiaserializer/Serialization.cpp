//
// Created by Student on 04.05.2017.
//

#include "Serialization.h"
namespace academia{
    Room::Room(int id_, const string &name_, academia::Room::Type type_) : id_(id_), name_(name_), type_(type_) {}

    void Room::Serialize(Serializer *ser){
        ser->IntegerField("id", id_);
        ser->StringField("name", name_);
        ser->Footer("room");
        ser->Header("room");
    }
}

