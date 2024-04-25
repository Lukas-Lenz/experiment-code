#ifndef HEADER_H_UPDATEQUEUE
#define HEADER_H_UPDATEQUEUE

#include "UpdateObject.cpp"


enum class UpdateTypes {
    TICK, CLOCK, DAY
};

class UpdateQueue {

    public: 

    void add(const UpdateObject &UpdateObject);
    void remove(const UpdateObject &UpdateObject);
    void update(const State &state, const UpdateTypes type, const int steps = 1);

    private:

    Time lastUpdate;
    std::vector<std::weak_ptr<UpdateObject>> update_objects;

};

#endif