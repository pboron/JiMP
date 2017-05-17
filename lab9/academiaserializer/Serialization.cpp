//
// Created by Student on 04.05.2017.
//

#include "Serialization.h"
namespace academia{
    Room::Room(int id, const std::string &name, Room::Type type) : name_(name), id_(id), type_(type) {}

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("id",id_);
        serializer->Separate();
        serializer->StringField("name",name_);
        serializer->Separate();
        serializer->StringField("type",TypeToString(type_));
        serializer->Footer("room");
    }
    void Building::Serialize(Serializer *serializer)const{
        serializer->Header("building");
        serializer->IntegerField("id",id_);
        serializer->Separate();
        serializer->StringField("name",name_);
        serializer->Separate();
        serializer->Header("rooms");
        for(int i=0; i<rooms_.size();++i){
            rooms_[i].Serialize(serializer);
            if(i!=rooms_.size()-1)
                serializer->Separate();
        }
        serializer->Footer("rooms");
        serializer->Footer("building");
    }

    Building::Building(int id, const std::string &name, const std::vector<Room> &rooms)
            :  name_(name), id_(id), rooms_(rooms) {}

}

