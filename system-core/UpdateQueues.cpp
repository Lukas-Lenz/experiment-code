#include "UpdateObject.cpp"

#include <memory>
#include <vector>

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


void UpdateQueue::add(const UpdateObject &UpdateObject) {

}

void UpdateQueue::update(const State &state) {

    //get time difference
    Time advanceBy = state.timeSince(lastUpdate);
    lastUpdate = state;

    for(auto updateObject_ptr : update_objects) {
    
        // check if the object still exists


        updateObject_ptr->update(state, advanceBy);
    }

}

clock_update.add()